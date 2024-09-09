#include <iostream>
#include <vector>

// 定义图像大小
const int IMAGE_WIDTH = 10;
const int IMAGE_HEIGHT = 10;

// 定义原始图像数据
std::vector<std::vector<int>> originalImage = {
    {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
    {15, 25, 35, 45, 55, 65, 75, 85, 95, 105},
    {20, 30, 40, 50, 60, 70, 80, 90, 100, 110},
    {25, 35, 45, 55, 65, 75, 85, 95, 105, 115},
    {30, 40, 50, 60, 70, 80, 90, 100, 110, 120},
    {35, 45, 55, 65, 75, 85, 95, 105, 115, 125},
    {40, 50, 60, 70, 80, 90, 100, 110, 120, 130},
    {45, 55, 65, 75, 85, 95, 105, 115, 125, 135},
    {50, 60, 70, 80, 90, 100, 110, 120, 130, 140},
    {55, 65, 75, 85, 95, 105, 115, 125, 135, 145}
};

// 进行采样
std::vector<std::vector<int>> downsampledImage;
const int DOWNSAMPLE_FACTOR = 2; // 降采样因子

void downsampleImage() {
    for (int i = 0; i < IMAGE_HEIGHT; i += DOWNSAMPLE_FACTOR) {
        std::vector<int> row;
        for (int j = 0; j < IMAGE_WIDTH; j += DOWNSAMPLE_FACTOR) {
            row.push_back(originalImage[i][j]);
        }
        downsampledImage.push_back(row);
    }
}

int main() {
    // 进行图像降采样
    downsampleImage();

    // 输出降采样后的图像数据
    std::cout << "Downsampled Image:" << std::endl;
    for (const auto& row : downsampledImage) {
        for (int pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
