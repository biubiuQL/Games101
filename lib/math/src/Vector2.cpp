
#include <math.h>
#include <iostream>
#include "../include/Vector2.hpp"
using namespace std;

Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
    // cout << "Vector2:-->默认构造函数" << endl;
}

Vector2::Vector2(const Vector2 &v3)
{
    x = v3.x;
    y = v3.y;
    // cout << "Vector2:-->浅拷贝构造函数" << endl;
}

Vector2::Vector2(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    // cout << "Vector2:-->有参构造函数" << endl;
}

Vector2::~Vector2()
{
    // cout << "Vector2----析构" << endl;
}

double Vector2::Dot(const Vector2 &a, const Vector2 &b)
{
    return a.x * b.x + a.y * b.y;
}