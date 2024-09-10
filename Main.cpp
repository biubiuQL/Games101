#include <iostream>
#include "Matrix_2_2.hpp"
#include "Eigen/Dense"

int main()
{
    Matrix_2_2 m1(1, 2, 3, 4);
    std::cout <<m1  << std::endl;
    std::cout << "Hello, world!" << std::endl;



    // 定义一个 2x2 的矩阵
    Eigen::Matrix2d mat;
    mat<<3,2.5,-1,mat(1,0)+mat(0,1);
    // mat(0, 0) = 3;
    // mat(1, 0) = 2.5;
    // mat(0, 1) = -1;
    // mat(1, 1) = mat(1, 0) + mat(0, 1);

    // 打印矩阵
    std::cout << "Matrix: \n" << mat << std::endl;
    return 0;
}