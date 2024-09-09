

#ifndef __VECTOR2__H
#define __VECTOR2__H
/*二维向量*/
class Vector2
{
public:
    double x, y, z;

    Vector2();

    Vector2(const Vector2 &v3);

    Vector2(double x, double y, double z);

    ~Vector2();

    /// @brief 两向量点乘
    /// @param a 向量a
    /// @param b 向量b
    /// @return 一个标量
    static double Dot(const Vector2 &a, const Vector2 &b);
};
#endif