#include <math.h>
#include <iostream>
#include "../include/Vector3.hpp"
using namespace std;

Vector3 Vector3::Add(const Vector3 &a, const Vector3 &b)
{
	Vector3 out;
	out.x = a.x + b.x;
	out.y = a.y + b.y;
	out.z = a.z + b.z;
	return out;
}

Vector3 Vector3::Sub(const Vector3 &a, const Vector3 &b)
{
	Vector3 out;
	out.x = a.x - b.x;
	out.y = a.y - b.y;
	out.z = a.z - b.z;
	return out;
}

Vector3 Vector3::Set(Vector3 &v3, double x, double y, double z)
{
	Vector3 out;
	out.x = v3.x + x;
	out.y = v3.y + y;
	out.z = v3.z + z;
	return out;
}

double Vector3::Dot(const Vector3 &a, const Vector3 &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::Cross(const Vector3 &a, const Vector3 &b)
{
	Vector3 out;
	out.x = a.y * b.z - a.z * b.y;
	out.y = -(a.x * b.z - a.z * b.x);
	out.z = a.x * b.y - a.y * b.x;
	return out;
}

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	// cout << "Vector3:-->默认构造函数" << endl;
}

Vector3::Vector3(const Vector3 &v3)
{
	x = v3.x;
	y = v3.y;
	z = v3.z;
	// cout << "Vector3:-->浅拷贝构造函数" << endl;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	// cout << "Vector3:-->有参构造函数" << endl;
}

Vector3::~Vector3()
{
	// cout << "Vector3----析构" << endl;
}

Vector3 &Vector3::Invert()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

Vector3 &Vector3::Zero()
{
	x = 0;
	y = 0;
	z = 0;
	return *this;
}

Vector3 &Vector3::Normalize()
{
	return *this /= Lenght();
}

double Vector3::Lenght()
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double *Vector3::ToArray()
{
	double *arr = new double[3];
	arr[0] = this->x;
	arr[1] = this->y;
	arr[2] = this->z;
	return arr;
}

#pragma region operator

Vector3 &Vector3::operator=(const Vector3 &v3)
{
	x = v3.x;
	y = v3.y;
	z = v3.z;
	return *this;
}

Vector3 &Vector3::operator+=(const Vector3 &v3)
{
	*this = Add(*this, v3);
	return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &v3)
{
	*this = Sub(*this, v3);
	return *this;
}

Vector3 &Vector3::operator*=(double multiplyScalar)
{
	x = x * multiplyScalar;
	y = y * multiplyScalar;
	z = z * multiplyScalar;
	return *this;
}

Vector3 &Vector3::operator/=(double multiplyScalar)
{
	x = x / multiplyScalar;
	y = y / multiplyScalar;
	z = z / multiplyScalar;
	return *this;
}

#pragma endregion

ostream &operator<<(ostream &cout, Vector3 &v3)
{
	cout << "[" << v3.x << "," << v3.y << "," << v3.z << "]" << endl;
	return cout;
}
