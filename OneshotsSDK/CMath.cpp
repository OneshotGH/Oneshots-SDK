#include "CMath.h"
#include "Interfaces.h"

CMath Math;

void CMath::NormalizeAngles(QAngle& angles)
{
	for (auto i = 0; i < 3; i++) {
		while (angles[i] < -180.0f) angles[i] += 360.0f;
		while (angles[i] > 180.0f) angles[i] -= 360.0f;
	}
}
Vector CMath::ExtrapolateTick(Vector p0, Vector v0) {
	return p0 + (v0 * Interfaces->Globals->interval_per_tick);
}
void CMath::NormalizeVector(Vector& vec)
{
	for (auto i = 0; i < 3; i++) {
		while (vec[i] < -180.0f) vec[i] += 360.0f;
		while (vec[i] > 180.0f) vec[i] -= 360.0f;
	}
	vec[2] = 0.f;
}
float CMath::NormalizeFloat(float angle)
{
	auto revolutions = angle / 360.f;
	if (angle > 180.f || angle < -180.f) {
		revolutions = round(abs(revolutions));
		if (angle < 0.f)
			angle = (angle + 360.f * revolutions);
		else
			angle = (angle - 360.f * revolutions);
		return angle;
	}
	return angle;
}
//--------------------------------------------------------------------------------
void CMath::ClampAngles(QAngle& angles)
{
	if (angles.x > 89.0f) angles.x = 89.0f;
	else if (angles.x < -89.0f) angles.x = -89.0f;

	if (angles.y > 180.0f) angles.y = 180.0f;
	else if (angles.y < -180.0f) angles.y = -180.0f;

	angles.z = 0;
}
//--------------------------------------------------------------------------------
void CMath::VectorTransform(const Vector& in1, const matrix3x4_t& in2, Vector& out)
{
	out[0] = in1.Dot(in2[0]) + in2[0][3];
	out[1] = in1.Dot(in2[1]) + in2[1][3];
	out[2] = in1.Dot(in2[2]) + in2[2][3];
}
//--------------------------------------------------------------------------------
void CMath::AngleVectors(const QAngle &angles, Vector& forward)
{
	float	sp, sy, cp, cy;

	SinCos(DEG2RAD(angles[1]), &sy, &cy);
	SinCos(DEG2RAD(angles[0]), &sp, &cp);

	forward.x = cp * cy;
	forward.y = cp * sy;
	forward.z = -sp;
}
//--------------------------------------------------------------------------------
void CMath::AngleVectors(const QAngle &angles, Vector& forward, Vector& right, Vector& up)
{
	float sr, sp, sy, cr, cp, cy;

	SinCos(DEG2RAD(angles[1]), &sy, &cy);
	SinCos(DEG2RAD(angles[0]), &sp, &cp);
	SinCos(DEG2RAD(angles[2]), &sr, &cr);

	forward.x = (cp * cy);
	forward.y = (cp * sy);
	forward.z = (-sp);
	right.x = (-1 * sr * sp * cy + -1 * cr * -sy);
	right.y = (-1 * sr * sp * sy + -1 * cr *  cy);
	right.z = (-1 * sr * cp);
	up.x = (cr * sp * cy + -sr * -sy);
	up.y = (cr * sp * sy + -sr * cy);
	up.z = (cr * cp);
}
//--------------------------------------------------------------------------------
void CMath::VectorAngles(const Vector& forward, QAngle& angles)
{
	/*if (forward[1] == 0.0f && forward[0] == 0.0f)
	{
		angles[0] = (forward[2] > 0.0f) ? 270.0f : 90.0f;
		angles[1] = 0.0f;
	}
	else
	{
		angles[0] = atan2(-forward[2], forward.Length2D()) * -180 / PI;
		angles[1] = atan2(forward[1], forward[0]) * 180 / PI;

		if (angles[1] > 90) angles[1] -= 180;
		else if (angles[1] < 90) angles[1] += 180;
		else if (angles[1] == 90) angles[1] = 0;
	}

	angles[2] = 0.0f;*/

	if (forward.y == 0 && forward.x == 0) {
		angles.x = forward.z > 0.f ? 270.f : 90.f;
		angles.y = 0;
	}

	else {
		angles.x = (atan2(-forward.z, forward.Length2D()) * 180 / PI);
		if (angles.x < 0)
			angles.x += 360;

		angles.y = (atan2(forward.y, forward.x) * 180 / PI);
		if (angles.y < 0)
			angles.y += 360;
	}

	angles.z = 0;
}

Vector CMath::CrossProduct(const Vector &a, const Vector &b)
{
	return Vector(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

void CMath::VectorAngles(const Vector& forward, Vector& up, QAngle& angles)
{
	Vector left = CrossProduct(up, forward);
	left.NormalizeInPlace();

	float forwardDist = forward.Length2D();

	if (forwardDist > 0.001f)
	{
		angles.x = atan2f(-forward.z, forwardDist) * 180 / PI_F;
		angles.y = atan2f(forward.y, forward.x) * 180 / PI_F;

		float upZ = (left.y * forward.x) - (left.x * forward.y);
		angles.z = atan2f(left.z, upZ) * 180 / PI_F;
	}
	else
	{
		angles.x = atan2f(-forward.z, forwardDist) * 180 / PI_F;
		angles.y = atan2f(-left.x, left.y) * 180 / PI_F;
		angles.z = 0;
	}
}
//--------------------------------------------------------------------------------
bool CMath::screen_transform(const Vector& in, Vector& out)
{
	static auto& w2sMatrix = Interfaces->EngineClient->WorldToScreenMatrix();
	
	out.x = w2sMatrix.m[0][0] * in.x + w2sMatrix.m[0][1] * in.y + w2sMatrix.m[0][2] * in.z + w2sMatrix.m[0][3];
	out.y = w2sMatrix.m[1][0] * in.x + w2sMatrix.m[1][1] * in.y + w2sMatrix.m[1][2] * in.z + w2sMatrix.m[1][3];
	out.z = 0.0f;

	float w = w2sMatrix.m[3][0] * in.x + w2sMatrix.m[3][1] * in.y + w2sMatrix.m[3][2] * in.z + w2sMatrix.m[3][3];

	if (w < 0.001f) {
		out.x *= 100000;
		out.y *= 100000;
		return false;
	}

	out.x /= w;
	out.y /= w;

	return true;
}
//--------------------------------------------------------------------------------
bool CMath::WorldToScreen(const Vector& in, Vector& out)
{
	if (screen_transform(in, out)) {
		int w, h;
		Interfaces->EngineClient->GetScreenSize(w, h);

		out.x = (w / 2.0f) + (out.x * w) / 2.0f;
		out.y = (h / 2.0f) - (out.y * h) / 2.0f;

		return true;
	}
	return false;
}
//--------------------------------------------------------------------------------
void CMath::SinCos(float a, float* s, float*c)
{
	*s = sin(a);
	*c = cos(a);
}


QAngle CMath::CalcAngle(Vector src, Vector dst)
{
	QAngle angles;
	Vector delta = dst - src;

	VectorAngles(delta, angles);

	angles.Normalize();

	return angles;
}


void CMath::AngleMatrix(const QAngle &angles, matrix3x4_t &matrix)
{
	float sr, sp, sy, cr, cp, cy;

	SinCos(DEG2RAD(angles[1]), &sy, &cy);
	SinCos(DEG2RAD(angles[0]), &sp, &cp);
	SinCos(DEG2RAD(angles[2]), &sr, &cr);

	// matrix = (YAW * PITCH) * ROLL
	matrix[0][0] = cp * cy;
	matrix[1][0] = cp * sy;
	matrix[2][0] = -sp;

	float crcy = cr * cy;
	float crsy = cr * sy;
	float srcy = sr * cy;
	float srsy = sr * sy;
	matrix[0][1] = sp * srcy - crsy;
	matrix[1][1] = sp * srsy + crcy;
	matrix[2][1] = sr * cp;

	matrix[0][2] = (sp*crcy + srsy);
	matrix[1][2] = (sp*crsy - srcy);
	matrix[2][2] = cr * cp;

	matrix[0][3] = 0.0f;
	matrix[1][3] = 0.0f;
	matrix[2][3] = 0.0f;
}

void CMath::MatrixSetColumn(const Vector &in, int column, matrix3x4_t &out)
{
	out[0][column] = in.x;
	out[1][column] = in.y;
	out[2][column] = in.z;
}

void CMath::AngleMatrix(const QAngle &angles, const Vector &position, matrix3x4_t &matrix)
{
	AngleMatrix(angles, matrix);
	MatrixSetColumn(position, 3, matrix);
}
