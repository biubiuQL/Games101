

#include "include/Vector3.hpp"
// #include "src/Vector3.cpp"
// #include "include/Matrix_2_2.hpp"
#include "src/Matrix_2_2.cpp"
#include "include/Matrix_3_3.hpp"
// #include "src/Matrix_3_3.cpp"
#include <string>
// #include "Printf.h"
#include <iostream>

using namespace std;

#define PI 3.1415926
int main()
{

	// ·······················向量练习·······················
	// cout << "向量" << endl;
	// Vector3 &v = *new Vector3(10, 20, 30);
	// Vector3 v1(1, 2, 3);
	// Vector3 v2(1, 2, 3);
	// Vector3::Add(v1, v2);
	// cout << "``````````" << endl;
	// Vector3 *v1 = new Vector3(1, 2, 3);
	// Vector3 *v2 = new Vector3(1, 2, 3);
	// Vector3::Add(*v1, *v2);
	// cout << "``````````" << endl;

	// double *arr = v.ToArray();
	// cout << arr[2] << endl;

	// Vector3 &v2 = v;
	// Vector3 v3 = v;
	// v.x = 10;
	// cout << &v << endl;
	// cout << &v2 << endl;
	// cout << &v3 << endl;
	// cout << v3.x << endl;
	// Vector3 v2(1, 1, 1);
	// Vector3 v4(1, 1, 1);
	// Vector3 v5 = v4 + v2 + v2;

	// cout << sizeof(int *) << endl;

	// Vector3 &v3 = *new Vector3(1, 2, 3);
	// Vector3 temp = v3.Invert();
	// cout << v3 << endl;
	// cout << v3.Lenght() << endl;

	// cout << v3 * 3 << endl;

	// cout << v3.Normalize() << endl;
	// // Print();
	// Vector3 out = Vector3::Add(Vector3(1, 2, 3), Vector3(1, 2, 3));
	// Vector3 v(1, 2, 3);
	// cout << v3 + v << endl;
	// cout << v3 * 3 << endl;

	// ·······················矩阵练习·······················
	// cout << "-------------mat1----------------" << endl;
	// Matrix_3_3 mat1;
	// mat1 << 1, -5, 3, 0, -2, 6, 7, 2, -4;
	// cout << mat1 << endl;
	// cout << "--------------mat2---------------" << endl;
	// Matrix_3_3 mat2;
	// mat2 << -8, 6, 1, 7, 0, -3, 2, 4, 5;
	// cout << mat2 << endl;
	// cout << "---------------矩阵和矩阵相乘--------------" << endl;
	// Matrix_3_3 mat3 = mat1 * mat2;
	// cout << mat3 << endl;
	// cout << "---------------向量和矩阵相乘--------------" << endl;
	// Matrix_3_3 mat4;
	// mat4 << -1, 0, 3, 5, 7, -6, 1, -4, 2;
	// cout << mat4 << endl;
	// cout << "-----------------------------" << endl;
	// cout << v * mat4 << endl;
	// cout << "---------------matrix_rotate-------------" << endl;
	// Matrix_3_3 mat1;
	// mat1 << 1, 0, 0, 0, 1, 0, 0, 0, 1;
	// Matrix_3_3 rotate1 = Matrix_3_3::rotate(AXIS::X, -22 * (PI / 180));
	// cout << rotate1 << endl;
	// Matrix_3_3 mat5 = mat1 * rotate1;
	// cout << mat5 << endl;
	// Matrix_3_3 rotate2 = Matrix_3_3::rotate(ROTATE_AXIS::X, -1);
	// Matrix_3_3 mat6 = mat5 * rotate2;
	// cout << mat6 << endl;

	// cout << "---------------matrix_scale-------------" << endl;
	// Vector3 vecScale(1, 2, 3);

	// Matrix_3_3 mat7 = Matrix_3_3 ::scale(vecScale);

	// Vector3 v2 = v * mat7;
	// cout <<v2 << endl;
	// cout << "---------------Det-------------" << endl;
	// Matrix_3_3 mat;
	// mat << 3, -2, 0, 1, 4, -3, -1, 0, 2;
	// cout << mat.Det();
	// // cout << "--------------矩阵乘以一个标量--------------" << endl;
	// Matrix_3_3 mat;
	// mat.Identity();
	// cout << (mat *= 3);

	cout << "--------------AlgebraicCofactor--------------" << endl;
	// Matrix_2_2 mat;
	// mat << 1, 0, 1, 0;

	// 伴随矩阵
	// Matrix_2_2 mat2 = mat.Adjoint();
	// // 矩阵的逆
	// Matrix_2_2 mat3 = mat2.operator*=(1 / mat.Det());
	// Matrix_2_2 mat4 = mat3 * mat;
	// cout << mat2 << endl;
	// cout << 1 / mat.Det() << endl;
	Matrix_3_3 mat;
	mat << 3, -2, 0, 1, 4, -3, -1, 0, 2;
	Matrix_3_3 mat5 = mat.Contrary();
	Matrix_3_3 mat6 = mat5 * mat;
	cout << mat6 << endl;
}