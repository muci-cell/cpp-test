#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define LEVEL 16

// 导出函数的宏
#ifdef BUILDING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
extern "C"
{
    // 将像素值量化为特定级别
    uchar get_value(int level, const uchar v)
    {
        int block_num = level - 1; // 15
        int block_size = 256 / block_num;
        for (int i = 1; i <= block_num; i++)
        {
            if (v > block_size * i)
            {
                continue;
            }
            int mid_value = block_size * i / 2;
            int left = block_size * (i - 1);
            int right = block_size * i - 1;
            return (v < mid_value) ? left : right;
        }
        return v;
    }

    // 量化灰度图像
    DLL_API void quantize(const Mat &input_img, Mat &output_img, int level)
    {
        output_img = input_img.clone();
        for (int i = 0; i < output_img.rows; i++)
        {
            const uchar *p1 = input_img.ptr<uchar>(i);
            uchar *p2 = output_img.ptr<uchar>(i);
            for (int j = 0; j < output_img.cols; j++)
            {
                p2[j] = get_value(level, p1[j]);
            }
        }
    }

    // 转换为灰度图像
    DLL_API void convert_to_gray(const Mat &input_img, Mat &gray_img)
    {
        cvtColor(input_img, gray_img, COLOR_BGR2GRAY);
    }

    // 下采样图像
    DLL_API void downsample_image(const Mat &input_img, Mat &downsampled_img)
    {
        resize(input_img, downsampled_img, Size(input_img.cols / 2, input_img.rows / 2));
    }
}
