#include <iostream>
#include <opencv2/opencv.hpp>  // 包含OpenCV头文件

using namespace std;
using namespace cv;  // 使用OpenCV命名空间
#define LEVEL 16

// v是像素值
uchar get_value(int level, uchar v)
{
    int block_num = level - 1;// 15
    int block_size = 256 / block_num;  //17
    // i从0循环到15
    for (int i = 1; i <= block_num; i++)
    {   // 循环从17,34。。。,255

        // 当v是3
        if (v > block_size * i)
        {
            continue;
        }

        int mid_value = block_size * i / 2;//8.5
        int left = block_size * (i - 1);//0
        int right = block_size * i - 1;//16
        if (v < mid_value)
        {
            return left;
        }
        else
        {
            return right;
        }
    }

    return v;
}
void quantizie(cv::Mat& input_img, int level)
{
    cv::Mat output_img = input_img.clone();
    output_img.setTo(0);
  

    for (int i = 0; i < output_img.rows; i++)
    {
        uchar* p1 = input_img.ptr<uchar>(i);
        uchar* p2 = output_img.ptr<uchar>(i);
        for (int j = 0; j < output_img.cols; j++)
        {
            p2[j] = get_value(level, p1[j]);
            //p2[j] = (p1[j] / range) * range;
        }
    }

    cv::imshow("quantize", output_img);
    cv::imwrite("quantize.png", output_img);
    cv::waitKey();
}
int main()
{
    // 设置全局 locale 为 UTF-8
    std::locale::global(std::locale("en_US.UTF-8"));
    // 读取图片
    Mat image = imread("test_image.jpg");  // 确保图片路径正确
    if (image.empty())  // 检查图片是否成功加载
    {
        cout << "无法打开或找到图片\n";
        return -1;  // 这里的 return 语句应正常工作
    }
    // 获取图像的分辨率信息
    int width = image.cols;
    int height = image.rows;

    // 打印输出分辨率
    std::cout << "图像分辨率: " << width << " x " << height << std::endl;

    // 转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // 使用 string 保存像素值
    std::string pixelValues;
    for (int row = 0; row < grayImage.rows; ++row) {
        for (int col = 0; col < grayImage.cols; ++col) {
            pixelValues += std::to_string(static_cast<int>(grayImage.at<uchar>(row, col))) + " ";
        }
    }

    // 一次性打印所有像素值
    std::cout << "灰度图像的像素值(前255个):" << std::endl;
    std::cout << pixelValues.substr(0, 255) << std::endl;


    // 下采样图像，尺寸降低为一半
    cv::Mat downsampledImage;
    cv::resize(image, downsampledImage, cv::Size(width / 2, height / 2));

    // 显示下采样的图像
    cv::imshow("Downsampled Image", downsampledImage);
    cv::waitKey(0);  // 等待按键后关闭窗口

    quantizie(grayImage, LEVEL);

    // 显示降低分辨率后的图像
    cv::imshow("Reduced Gray Resolution Image", grayImage);
    cv::waitKey(0);  // 等待按键后关闭窗口

    cout << "按任意键关闭窗口..." << endl;  // 提示用户按键
    waitKey(0);  // 等待按键

    return 0;  // 确保这里有 return 语句
}

