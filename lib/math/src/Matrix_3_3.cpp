#include "../include/Matrix_3_3.hpp"
#include "../include/Matrix_2_2.hpp"
#include "../include/Vector3.hpp"
#include <cstddef>
#include <math.h>
#include <map>

using namespace std;

double Matrix_3_3::getElement(int row, int column)
{
    return this->data[row * 3 + column];
}

void Matrix_3_3::setElement(int row, int column, double v)
{
    this->data[row * 3 + column] = v;
}

Matrix_3_3 Matrix_3_3::rotate(AXIS axis, double radian)
{
    Matrix_3_3 mat;
    switch (axis)
    {
    case X:
        mat << 1, 0, 0, 0, cos(radian), sin(radian), 0, -sin(radian), cos(radian);
        break;
    case Y:
        mat << cos(radian), 0, -sin(radian), 0, 1, 0, sin(radian), 0, cos(radian);
        break;
    case Z:
        mat << cos(radian), sin(radian), 0,
            -sin(radian), cos(radian), 0,
            0, 0, 1;
        break;
    default:
        break;
    }
    return mat;
}

Matrix_3_3 Matrix_3_3::rotate(const Vector3 &vector, double radian)
{
    Matrix_3_3 mat;
    mat
        << pow(vector.x, 2) * (1 - cos(radian)) + cos(radian) << vector.x * vector.y * (1 - cos(radian)) + vector.z * sin(radian) << vector.x * vector.z * (1 - cos(radian)) - vector.y * sin(radian)
        << vector.x * vector.y * (1 - cos(radian)) - vector.z * sin(radian) << pow(vector.y, 2) * (1 - cos(radian)) + cos(radian) << vector.y * vector.z * (1 - cos(radian)) + vector.x * sin(radian)
        << vector.x * vector.z * (1 - cos(radian)) + vector.y * sin(radian) << vector.y * vector.z * (1 - cos(radian)) - vector.x * sin(radian) << pow(vector.z, 2) * (1 - cos(radian)) + cos(radian);
    return mat;
}

Matrix_3_3 Matrix_3_3::scale(const Vector3 &vector3)
{
    Matrix_3_3 mat;
    mat << vector3.x, 0, 0, 0, vector3.y, 0, 0, 0, vector3.z;
    return mat;
}

Matrix_3_3 Matrix_3_3::orthogonalProjection(const Vector3 &vector3)
{
    Matrix_3_3 mat;
    return mat;
}

Matrix_3_3 Matrix_3_3::Mirror(AXIS axis)
{
    Matrix_3_3 mat;
    switch (axis)
    {
    case X:
        mat << 1, 0, 0, 0, -1, 0, 0, 0, -1;
        break;
    case Y:
        mat << 0, 0, -1, 0, 1, 0, 0, 0, -1;
        break;
    case Z:
        mat << 0, 0, -1, 0, -1, 0, 0, 0, 1;
        break;

    default:
        mat.Identity();
        break;
    }
    return mat;
}

double Matrix_3_3::Det()
{
    double m00 = this->getElement(0, 0), m01 = this->getElement(0, 1), m02 = this->getElement(0, 2);
    double m10 = this->getElement(1, 0), m11 = this->getElement(1, 1), m12 = this->getElement(1, 2);
    double m20 = this->getElement(2, 0), m21 = this->getElement(2, 1), m22 = this->getElement(2, 2);
    double out = m00 * (m11 * m22 - m21 * m12) - m01 * (m10 * m22 - m20 * m12) + m02 * (m10 * m21 - m11 * m20);
    return out;
}

Matrix_3_3 Matrix_3_3::Contrary()
{
    if (this->Det() == 0)
    {
        cout << "当前矩阵的行列式不能等于0" << endl;
        Matrix_3_3 mat;
        return mat;
    }
    else
    {
        return this->Adjoint() *= 1 / this->Det();
    }
}

Matrix_3_3 &Matrix_3_3::Identity()
{
    for (int i = 0; i < 9; i++)
    {
        this->data[i] = i % 4 == 0 ? 1 : 0;
    }
    return *this;
}

Matrix_3_3 Matrix_3_3::Adjoint()
{
    Matrix_3_3 mat;
    for (int i = 0; i < this->data.size(); i++)
    {
        double element = this->data[i];

        int elRow = floor(i / 3);
        int elCol = i % 3;
        mat << this->AlgebraicCofactor(elRow, elCol);
    }
    mat.Transposition();
    return mat;
}

double Matrix_3_3::AlgebraicCofactor(int row, int col)
{
    Matrix_2_2 m2x2;
    for (int i = 0; i < this->data.size(); i++)
    {
        int elRow = floor(i / 3);
        int elCol = i % 3;
        if (row == elRow || col == elCol)
        {
            continue;
        }
        m2x2 << this->data[i];
    }

    return pow(-1, row + col) * m2x2.Det();
}

Matrix_3_3 &Matrix_3_3::Transposition()
{
    Matrix_3_3 mat;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat.setElement(j, i, this->getElement(i, j));
        }
    }
    *this = mat;
    return *this;
}

Matrix_3_3 &Matrix_3_3::operator<<(double v)
{
    if (this->data.size() < 9)
    {
        int length = this->data.size();
        this->data[length] = v;
    }
    return *this;
}

Matrix_3_3 &Matrix_3_3::operator,(double v)
{
    if (this->data.size() < 9)
    {
        int length = this->data.size();
        this->data[length] = v;
    }
    return *this;
}

Matrix_3_3 &Matrix_3_3::operator=(Matrix_3_3 &mat)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            double v = mat.getElement(i, j);
            this->setElement(i, j, v);
        }
    }
    return *this;
}

Matrix_3_3 &Matrix_3_3::operator*=(double v)
{
    for (int i = 0; i < this->data.size(); i++)
    {
        this->data[i] *= v;
    }
    return *this;
}

Matrix_3_3 Matrix_3_3::operator*(double v)
{
    Matrix_3_3 mat;
    for (int i = 0; i < this->data.size(); i++)
    {
        mat.data[i] = this->data[i] * v;
    }
    return mat;
}

Vector3 Matrix_3_3::operator*(Vector3 &v3)
{
    Matrix_3_3 &mat = *this;
    map<int, double> _map;
    for (int i = 0; i < 3; i++)
    {
        Vector3 v(mat.getElement(0, i), mat.getElement(1, i), mat.getElement(2, i));
        double value = Vector3::Dot(v3, v);
        _map[i] = value;
    }
    Vector3 out(_map[0], _map[1], _map[2]);
    return out;
}

Matrix_3_3 Matrix_3_3::operator*(Matrix_3_3 &mat)
{
    Matrix_3_3 &a = *this;
    Matrix_3_3 &b = mat;
    Matrix_3_3 c;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Vector3 v1(a.getElement(i, 0), a.getElement(i, 1), a.getElement(i, 2));
            Vector3 v2(b.getElement(0, j), b.getElement(1, j), b.getElement(2, j));
            double value = Vector3::Dot(v1, v2);
            c.setElement(i, j, value);
        }
    }
    return c;
}

Matrix_3_3 &Matrix_3_3::operator*=(Matrix_3_3 &mat)
{
    Matrix_3_3 temp = *this * mat;
    *this = temp;
    return *this;
}

Matrix_3_3 Matrix_3_3::operator+(Matrix_3_3 &mat)
{
    Matrix_3_3 out;
    out.Identity();
    for (int i = 0; i < out.data.size(); i++)
    {
        out.data[i] = this->data[i] + mat.data[i];
    }
    return out;
}

Matrix_3_3 &Matrix_3_3::operator+=(Matrix_3_3 &mat)
{
    Matrix_3_3 temp = *this + mat;
    *this = temp;
    return *this;
}

ostream &operator<<(ostream &cout, Matrix_3_3 &mat3)
{
    cout
        << "[" << mat3.getElement(0, 0) << "," << mat3.getElement(0, 1) << "," << mat3.getElement(0, 2) << endl
        << " " << mat3.getElement(1, 0) << "," << mat3.getElement(1, 1) << "," << mat3.getElement(1, 2) << endl
        << " " << mat3.getElement(2, 0) << "," << mat3.getElement(2, 1) << "," << mat3.getElement(2, 2) << "]";
    return cout;
}