// test_dll.cpp
#include <iostream>
#include <opencv2/opencv.hpp>
#include "lena-gray.h"  // 包含 DLL 的头文件

using namespace std;
using namespace cv;

int main() {
    // 加载一张图像
    Mat input_img = imread("lena.jpg");  // 替换为你要测试的图片路径
    if (input_img.empty()) {
        cerr << "无法加载图像!" << endl;
        return -1;
    }

    // 转换为灰度图像
    Mat gray_img;
    convert_to_gray(input_img, gray_img);

    // 量化灰度图像
    Mat quantized_img;
    int level = 16;  // 你可以根据需要更改量化级别
    quantize(gray_img, quantized_img, level);

    // 下采样图像
    Mat downsampled_img;
    downsample_image(quantized_img, downsampled_img);

    // 显示结果
    imshow("1", input_img);
    imshow("2", gray_img);
    imshow("3", quantized_img);
    imshow("4", downsampled_img);

    // 等待用户按键
    waitKey(0);
    return 0;
}
