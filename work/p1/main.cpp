#include "Triangle.cpp"
#include "Rasterizer.cpp"
#include <Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

using namespace Eigen;

// 绕z轴的旋转矩阵
Eigen::Matrix4f get_model_matrix(float angle)
{
    Matrix4f model = Matrix4f::Identity();
    angle = M_PI / 180.0f * angle;
    Matrix4f rotate;
    rotate << cos(angle), -sin(angle), 0, 0,
        sin(angle), cos(angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;
    return rotate * model;
}

// 视图矩阵
Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Matrix4f view = Matrix4f::Identity();

    Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0],
        0, 1, 0, -eye_pos[1],
        0, 0, 1, -eye_pos[2],
        0, 0, 0, 1;

    view = translate * view;
    return view;
}

// 透视投影矩阵
// eye_fov 垂直视角 (角度)
// aspect_ratio 纵横比
// zNear 近裁剪面
// zFar 远裁剪面
Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    float l, r, b, t, n, f;

    t = tan(M_PI / 180.0f * eye_fov / 2) * zNear;
    b = -t;
    r = aspect_ratio * t;
    l = -r;
    n = zNear;
    f = zFar;
    // 注意：这个矩阵是扩大了z的倍数后的矩阵
    Matrix4f perspective = Matrix4f::Identity();

    // 挤压矩阵
    Matrix4f squeeze;

    squeeze << n, 0, 0, 0,
        0, n, 0, 0,
        0, 0, n + f, -n * f,
        0, 0, 1, 0;

    // 正交矩阵
    Matrix4f orthogonal;

    Matrix4f translate;
    translate << 1, 0, 0, -(r + l) / 2,
        0, 1, 0, -(t + b) / 2,
        0, 0, 1, -(n + f) / 2,
        0, 0, 0, 1;
    Matrix4f scale;
    scale << 2 / (r - l), 0, 0, 0,
        0, 2 / (t - b), 0, 0,
        0, 0, 2 / (n - f), 0,
        0, 0, 0, 1;

    orthogonal = scale * translate;
    perspective = orthogonal * squeeze;
    return perspective;
}

int main(int argc, const char **argv)
{

    float angle = 0;
    rst::Rasterizer r(700, 700);
    Eigen::Vector3f eye_pos = {0, 0, 5};
    // 标准设备坐标系下的顶点位置
    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    auto pos_id = r.load_positions(pos);
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;
    while (key != 27)
    {
        // r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a')
        {
            angle += 10;
        }
        else if (key == 'd')
        {
            angle -= 10;
        }
    }

    return 0;
}
