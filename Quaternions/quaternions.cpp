#include "quaternions.h"
#include <string.h>

Quaternion::Quaternion()
{
}

Quaternion::Quaternion(float4 vec)
{
	memcpy(&vec_, &vec, sizeof(float4));
}

Quaternion::Quaternion(float3 vec)
{
	vec_.s = 0.0f;
	vec_.x = vec.x;
	vec_.y = vec.y;
	vec_.z = vec.z;
}


Quaternion::~Quaternion()
{
}

Quaternion& Quaternion::operator=(const Quaternion &rhs)
{
	
	memcpy(&this->vec_, &rhs.vec_, sizeof(float4));

	return *this;
}

Quaternion Quaternion::operator=(const float4 &rhs)
{
	Quaternion lhs;
	memcpy(&lhs.vec_, &rhs, sizeof(float4));

	return lhs;
}

Quaternion Quaternion::operator*(const Quaternion &rhs)
{
	Quaternion prod;
	const float4 &v1 = this->vec_;
	const float4 &v2 = rhs.vec_;

	prod.vec_.s = (v1.s * v2.s) - (v1.x * v2.x) - (v1.y * v2.y) - (v1.z * v2.z);
	prod.vec_.x = (v1.s * v2.x) + (v1.x * v2.s) + (v1.y * v2.z) - (v1.z * v2.y);
	prod.vec_.y = (v1.s * v2.y) - (v1.x * v2.z) + (v1.y * v2.s) + (v1.z * v2.x);
	prod.vec_.z = (v1.s * v2.z) + (v1.x * v2.y) - (v1.y * v2.x) + (v1.z * v2.s);
	return prod;
}

Quaternion Quaternion::operator+(const Quaternion &rhs)
{
	Quaternion prod;
	const float4 &v1 = this->vec_;
	const float4 &v2 = rhs.vec_;

	prod.vec_.s = v1.s + v2.s;
	prod.vec_.x = v1.x + v2.x;
	prod.vec_.y = v1.y + v2.y;
	prod.vec_.z = v1.z + v2.z;
	return prod;
}

Quaternion Quaternion::operator-(const Quaternion &rhs)
{
	Quaternion prod;
	const float4 &v1 = this->vec_;
	const float4 &v2 = rhs.vec_;

	prod.vec_.s = v1.s - v2.s;
	prod.vec_.x = v1.x - v2.x;
	prod.vec_.y = v1.y - v2.y;
	prod.vec_.z = v1.z - v2.z;
	return prod;
}

Quaternion& Quaternion::operator*=(const float &rhs)
{
	float4 &v1 = this->vec_;
	v1.s *= rhs;
	v1.x *= rhs;
	v1.y *= rhs;
	v1.z *= rhs;

	return *this;
}

float Quaternion::scalar()
{
	return vec_.s;
}

float3 Quaternion::vector()
{
	float3 vec3;
	vec3.x = vec_.x;
	vec3.y = vec_.y;
	vec3.z = vec_.z;
	return vec3;
}

float Quaternion::dot(const float3 &a3, const float3 &b3)
{
	Quaternion a(a3);
	Quaternion b(b3);

	Quaternion prod1 = a * b;
	Quaternion prod2;

	prod2 = b * a;

	Quaternion dp = prod1 + prod2;
	dp *= -0.5f;

	return dp.scalar();
}

float3  Quaternion::cross(const float3 &a3, const float3 &b3)
{
	Quaternion a(a3);
	Quaternion b(b3);

	Quaternion prod1 = a * b;
	Quaternion prod2;

	prod2 = b * a;

	Quaternion cp = prod1 - prod2;
	cp *= 0.5f;
	return cp.vector();
}