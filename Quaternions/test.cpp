#include "quaternions.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	float3 a(1.0, 0.0, 0.0);
	float3 b(1.0, 0.0, 0.0);

	float dp = Quaternion::dot(a, b);
	float3 cp = Quaternion::cross(a, b);
	return 0;
}