#include <map>
#include <iostream>
#ifndef __Matrix_2_2__H
#define __Matrix_2_2__H
using namespace std;

/**2X2矩阵，使用的左手坐标系，行向量表示*/
class Matrix_2_2
{
public:
    Matrix_2_2(){
        
    }
    Matrix_2_2(float m00, float m01, float m10, float m11)
    {
        data[0] = m00;
        data[1] = m01;
        data[2] = m10;
        data[3] = m11;
    }

    map<int, double> data;

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

    /// @brief 行列式
    /// @return 值
    double Det();

    /// @brief 代数余子式
    /// @return
    double AlgebraicCofactor(int row, int col);

    /// @brief 当前矩阵的伴随矩阵
    /// @return
    Matrix_2_2 Adjoint();

    /// @brief 转置
    /// @return *this
    Matrix_2_2 &Transposition();

    /// @brief 当前矩阵的逆
    /// @return
    Matrix_2_2 Contrary();

    /// @brief 向矩阵中添加元素
    /// @param v value
    /// @return *this
    Matrix_2_2 &operator<<(double v);

    /// @brief 向矩阵中添加元素
    /// @param v value
    /// @return *this
    Matrix_2_2 &operator,(double v);

    /// @brief 矩阵拷贝：设置当前矩阵使其与指定矩阵相等
    /// @param mat 输入
    /// @return *this
    Matrix_2_2 &operator=(Matrix_2_2 &mat);

    /// @brief 和矩阵相乘
    /// @param mat 传入矩阵
    /// @return 一个新的矩阵
    Matrix_2_2 operator*(Matrix_2_2 &mat);

    /// @brief 和矩阵相乘
    /// @param mat
    /// @return *this
    Matrix_2_2 &operator*=(Matrix_2_2 &mat);

    Matrix_2_2 &operator*=(double v);
};

/**打印*/
ostream &operator<<(ostream &cout, Matrix_2_2 &mat);

#endif