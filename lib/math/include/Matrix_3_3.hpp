#include <iostream>
#include "../include/Vector3.hpp"
#include <map>
#ifndef __MATRIX_3_3__H
#define __MATRIX_3_3__H
using namespace std;

/**坐标轴*/
enum AXIS
{
    X,
    Y,
    Z,
};

/**3X3矩阵，使用的左手坐标系，行向量表示*/
class Matrix_3_3
{

public:
    map<int, double> data;

    /// @brief 获取绕指定轴的一个旋转矩阵
    /// @param axis 旋转轴
    /// @param angle 旋转的弧度
    /// @return Matrix_3_3
    Matrix_3_3 static rotate(AXIS axis, double radian);

    /// @brief 获取绕任意轴的一个旋转矩阵
    /// @param vector 过原点的单位向量
    /// @param radian 旋转的弧度
    /// @return Matrix_3_3
    Matrix_3_3 static rotate(const Vector3 &vector, double radian);

    /// @brief 获取缩放矩阵
    /// @param Vector3 缩放向量
    /// @return
    Matrix_3_3 static scale(const Vector3 &vector3);

    /// @brief 正交投影
    /// @param vector3 过原点且垂直于指定投影平面的单位向量
    /// @return
    Matrix_3_3 static orthogonalProjection(const Vector3 &vector3);

    /// @brief 获取镜像矩阵
    /// @param axis 指定轴
    /// @return
    Matrix_3_3 static Mirror(AXIS axis);

    /// @brief 获取矩阵中的元素
    /// @param row 行:下标从0开始
    /// @param column 列:下标从0开始
    /// @return
    double getElement(int row, int column);

    /// @brief 设置矩阵中的元素
    /// @param row 行:下标从0开始
    /// @param column 列:下标从0开始
    /// @param v value
    void setElement(int row, int column, double v);

    /// @brief 设置当前矩阵为单位矩阵
    /// @return *this
    Matrix_3_3 &Identity();

    /// @brief 当前矩阵的伴随矩阵
    /// @return
    Matrix_3_3 Adjoint();

    /// @brief 代数余子式
    /// @return
    double AlgebraicCofactor(int row, int col);

    /// @brief 转置
    /// @return *this
    Matrix_3_3 &Transposition();

    /// @brief 行列式
    /// @return 值
    double Det();

    /// @brief 当前矩阵的逆
    /// @return
    Matrix_3_3 Contrary();

    /// @brief 向矩阵中添加元素
    /// @param v value
    /// @return *this
    Matrix_3_3 &operator<<(double v);

    /// @brief 向矩阵中添加元素
    /// @param v value
    /// @return *this
    Matrix_3_3 &operator,(double v);

    /// @brief 矩阵拷贝：设置当前矩阵使其与指定矩阵相等
    /// @param mat 输入
    /// @return *this
    Matrix_3_3 &operator=(Matrix_3_3 &mat);

    /// @brief 矩阵和值相乘
    /// @param v value
    /// @return *this
    Matrix_3_3 &operator*=(double v);

    /// @brief 矩阵和值相乘
    /// @param v value
    /// @return 一个新的矩阵
    Matrix_3_3 operator*(double v);

    /// @brief 当前矩阵和向量相乘
    /// @param vector
    /// @return 一个新的矩阵
    Vector3 operator*(Vector3 &vector);

    /// @brief 和矩阵相乘
    /// @param mat 传入矩阵
    /// @return 一个新的矩阵
    Matrix_3_3 operator*(Matrix_3_3 &mat);

    /// @brief 和矩阵相乘
    /// @param mat
    /// @return *this
    Matrix_3_3 &operator*=(Matrix_3_3 &mat);

    /// @brief 和矩阵相加
    /// @param mat
    /// @return 一个新的矩阵
    Matrix_3_3 operator+(Matrix_3_3 &mat);

    /// @brief 和矩阵相加
    /// @param mat
    /// @return *this
    Matrix_3_3 &operator+=(Matrix_3_3 &mat);
};

/**打印*/
ostream &operator<<(ostream &cout, Matrix_3_3 &mat3);

#endif
