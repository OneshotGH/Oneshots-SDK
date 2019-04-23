#pragma once
#include "Matrix3x4_t.h"
#include "QAngle.h"

#define PI 3.14159265358979323846f
#define RADPI 57.295779513082f
#define PI_F	((float)(PI)) 
//#define DEG2RAD( x ) ( ( float )( x ) * ( float )( ( float )( PI ) / 180.0f ) )
//#define RAD2DEG( x ) ( ( float )( x ) * ( float )( 180.0f / ( float )( PI ) ) )

class CMath
{
public:
	void NormalizeAngles(QAngle & angles);
	Vector ExtrapolateTick(Vector p0, Vector v0);
	void NormalizeVector(Vector & vec);
	float NormalizeFloat(float angle);
	void ClampAngles(QAngle & angles);
	void VectorTransform(const Vector & in1, const matrix3x4_t & in2, Vector & out);
	void AngleVectors(const QAngle & angles, Vector & forward);
	void AngleVectors(const QAngle & angles, Vector & forward, Vector & right, Vector & up);
	void VectorAngles(const Vector & forward, QAngle & angles);
	Vector CrossProduct(const Vector & a, const Vector & b);
	void VectorAngles(const Vector & forward, Vector & up, QAngle & angles);
	bool screen_transform(const Vector & in, Vector & out);
	bool WorldToScreen(const Vector & in, Vector & out);
	void SinCos(float a, float * s, float * c);
	QAngle CalcAngle(Vector src, Vector dst);
	void AngleMatrix(const QAngle & angles, matrix3x4_t & matrix);
	void MatrixSetColumn(const Vector & in, int column, matrix3x4_t & out);
	void AngleMatrix(const QAngle & angles, const Vector & position, matrix3x4_t & matrix);
};

extern CMath Math;