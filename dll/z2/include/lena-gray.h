#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <opencv2/opencv.hpp>

#ifdef BUILDING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" {
    DLL_API void quantize(const cv::Mat& input_img, cv::Mat& output_img, int level);
    DLL_API void convert_to_gray(const cv::Mat& input_img, cv::Mat& gray_img);
    DLL_API void downsample_image(const cv::Mat& input_img, cv::Mat& downsampled_img);
}

#endif // IMAGE_PROCESSING_H
