#ifndef QUATERNIONS_H
#define QUATERNIONS_H

typedef struct float4 {
	float4(float si, float xi, float yi, float zi)
	{
		s = si;
		x = xi;
		y = yi;
		z = zi;
	}

	float4()
	{
		s = 0.0f;
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	float s;
	float x;
	float y;
	float z;
}float4;

typedef struct float3 {
	float3(float xi, float yi, float zi)
	{	
		x = xi;
		y = yi;
		z = zi;
	}

	float3()
	{		
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	
	float x;
	float y;
	float z;
}float3;

class Quaternion {
public:
	static float dot(const float3 &a, const float3 &b);
	static float3 cross(const float3 &a, const float3 &b);
	Quaternion();
	Quaternion(float4 vec);
	Quaternion(float3 vec);
	~Quaternion();
	Quaternion& operator=(const Quaternion &rhs);
	Quaternion operator=(const float4 &rhs);
	Quaternion operator*(const Quaternion &rhs);
	Quaternion& operator*=(const float &rhs);
	Quaternion operator+(const Quaternion &rhs);
	Quaternion operator-(const Quaternion &rhs);
	float scalar();
	float3 vector();
private:
	float4 vec_;
};
#endif
