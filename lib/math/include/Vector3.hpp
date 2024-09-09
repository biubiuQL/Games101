
#ifndef __VECTOR3__H
#define __VECTOR3__H
#include <math.h>
#include <iostream>
using namespace std;

/*三维向量*/
class Vector3
{

public:
	/// @brief 逐元素向量加法
	/// @param a 向量a
	/// @param b 向量b
	/// @return 新的向量
	static Vector3 Add(const Vector3 &a, const Vector3 &b);

	/// @brief 逐元素向量加法
	/// @param a 向量a
	/// @param b 向量b
	/// @return 新的向量
	static Vector3 Sub(const Vector3 &a, const Vector3 &b);

	/// @brief 设置向量各分量值
	/// @param v3 输入向量
	/// @param x x的值
	/// @param y y的值
	/// @param z z的值
	/// @return
	static Vector3 Set(Vector3 &v3, double x, double y, double z);

	/// @brief 两向量点乘
	/// @param a 向量a
	/// @param b 向量b
	/// @return 一个标量
	static double Dot(const Vector3 &a, const Vector3 &b);

	/// @brief 两向量叉乘
	/// @param a 向量a
	/// @param b 向量b
	/// @return 向量
	static Vector3 Cross(const Vector3 &a, const Vector3 &b);

public:
	double x, y, z;

	Vector3();

	Vector3(const Vector3 &v3);

	Vector3(double x, double y, double z);

	~Vector3();

	/// @brief 当前向量取反
	/// @return *this
	Vector3 &Invert();

	/// @brief 当前向量归零
	/// @return *this
	Vector3 &Zero();

	/// @brief 归一化
	/// @return *this
	Vector3 &Normalize();

	/// @brief 计算向量的长度(模)
	/// @return
	double Lenght();

	/// @brief 转换为数组
	/// @return
	double *ToArray();

#pragma region operator

	/// @brief 向量拷贝：设置当前向量使其与指定向量相等
	/// @param v3 输入向量
	/// @return *this
	Vector3 &operator=(const Vector3 &v3);

	/// @brief 向量加法：逐元素向量加法
	/// @param v3 输入向量
	/// @return *this
	Vector3 &operator+=(const Vector3 &v3);

	/// @brief 向量减法：逐元素向量加法
	/// @param v3 输入向量
	/// @return *this
	Vector3 &operator-=(const Vector3 &v3);

	/// @brief 向量数乘：将当前向量数乘指定标量
	/// @param multiplyScalar 缩放倍数
	/// @return *this
	Vector3 &operator*=(double multiplyScalar);

	/// @brief 向量数除：将当前向量数除指定标量
	/// @param multiplyScalar 缩放倍数
	/// @return *this
	Vector3 &operator/=(double multiplyScalar);

#pragma endregion

private:
};

/// @brief 打印
/// @param cout
/// @param v3
/// @return
ostream &operator<<(ostream &cout, Vector3 &v3);
#endif
