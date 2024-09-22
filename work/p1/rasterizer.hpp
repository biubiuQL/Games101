#include <vector>
#include <Eigen/Eigen>
#include "Triangle.hpp"
// 光栅器
namespace rst
{

    enum class Primitive
    {
        Line,
        Triangle
    };

    struct pos_buf_id
    {
        int pos_id = 0;
    };

    struct ind_buf_id
    {
        int ind_id = 0;
    };
    class Rasterizer
    {
    public:
        Rasterizer(int w, int h);
        pos_buf_id load_positions(const std::vector<Eigen::Vector3f> &positions);
        ind_buf_id load_indices(const std::vector<Eigen::Vector3i> &indices);
        void set_model(const Eigen::Matrix4f &m);
        void set_view(const Eigen::Matrix4f &v);
        void set_projection(const Eigen::Matrix4f &p);

        void draw(pos_buf_id pos_buffer, ind_buf_id ind_buffer, Primitive type);
        void set_pixel(const Eigen::Vector3f &point, const Eigen::Vector3f &color);
        std::vector<Eigen::Vector3f> &frame_buffer() { return frame_buf; }

    private:
        int width, height;
        Eigen::Matrix4f model;
        Eigen::Matrix4f view;
        Eigen::Matrix4f projection;

        std::map<int, std::vector<Eigen::Vector3f>> pos_buf;
        std::map<int, std::vector<Eigen::Vector3i>> ind_buf;

        // 帧缓存
        std::vector<Eigen::Vector3f> frame_buf;
        // 深度缓存
        std::vector<float> depth_buf;

        int next_id = 0;
        int get_next_id() { return next_id++; }

        void draw_line(Eigen::Vector3f begin, Eigen::Vector3f end);
        void rasterize_wireframe(const Triangle &t);
    };
};