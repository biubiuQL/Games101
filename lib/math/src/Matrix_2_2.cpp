
#include "../include/Matrix_2_2.hpp"
#include "../include/Vector2.hpp"
#include <cstddef>
#include <math.h>
#include <map>

double Matrix_2_2::getElement(int row, int column)
{
    return this->data[row * 2 + column];
}

void Matrix_2_2::setElement(int row, int column, double v)
{
    this->data[row * 2 + column] = v;
}

double Matrix_2_2::Det()
{
    double m00 = this->getElement(0, 0), m01 = this->getElement(0, 1);
    double m10 = this->getElement(1, 0), m11 = this->getElement(1, 1);
    return m00 * m11 - m10 * m01;
}

double Matrix_2_2::AlgebraicCofactor(int row, int col)
{
    double v;
    for (int i = 0; i < this->data.size(); i++)
    {
        int elRow = floor(i / 2);
        int elCol = i % 2;
        if (row == elRow || col == elCol)
        {
            continue;
        }
        v = this->data[i];
    }
    return pow(-1, row + col) * v;
}

Matrix_2_2 Matrix_2_2::Adjoint()
{
    Matrix_2_2 mat;
    for (int i = 0; i < this->data.size(); i++)
    {
        double element = this->data[i];

        int elRow = floor(i / 2);
        int elCol = i % 2;
        mat << this->AlgebraicCofactor(elRow, elCol);
    }
    mat.Transposition();
    return mat;
}

Matrix_2_2 &Matrix_2_2::Transposition()
{
    Matrix_2_2 mat;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat.setElement(j, i, this->getElement(i, j));
        }
    }
    *this = mat;
    return *this;
}

Matrix_2_2 Matrix_2_2::Contrary()
{
    if (this->Det() == 0)
    {
        cout << "当前矩阵的行列式不能等于0" << endl;
        Matrix_2_2 mat;
        return mat;
    }
    else
    {
        return this->Adjoint() *= 1 / this->Det();
    }
}

Matrix_2_2 &Matrix_2_2::operator<<(double v)
{
    if (this->data.size() < 4)
    {
        int length = this->data.size();
        this->data[length] = v;
    }
    return *this;
}

Matrix_2_2 &Matrix_2_2::operator,(double v)
{
    if (this->data.size() < 4)
    {
        int length = this->data.size();
        this->data[length] = v;
    }
    return *this;
}

Matrix_2_2 &Matrix_2_2::operator=(Matrix_2_2 &mat)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            double v = mat.getElement(i, j);
            this->setElement(i, j, v);
        }
    }
    return *this;
}

Matrix_2_2 &Matrix_2_2::operator*=(double v)
{
    for (int i = 0; i < this->data.size(); i++)
    {
        this->data[i] *= v;
    }
    return *this;
}

Matrix_2_2 Matrix_2_2::operator*(Matrix_2_2 &mat)
{
    Matrix_2_2 &a = *this;
    Matrix_2_2 &b = mat;
    Matrix_2_2 c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Vector2 v1(a.getElement(i, 0), a.getElement(i, 1), 0);
            Vector2 v2(b.getElement(0, j), b.getElement(1, j), 0);
            double value = Vector2::Dot(v1, v2);
            c.setElement(i, j, value);
        }
    }
    return c;
}

Matrix_2_2 &Matrix_2_2::operator*=(Matrix_2_2 &mat)
{
    Matrix_2_2 temp = *this * mat;
    *this = temp;
    return *this;
}

/**打印*/
ostream &operator<<(ostream &cout, Matrix_2_2 &mat)
{
    cout
        << "[" << mat.getElement(0, 0) << "," << mat.getElement(0, 1) << endl
        << " " << mat.getElement(1, 0) << "," << mat.getElement(1, 1) << "]" << endl;
    return cout;
}