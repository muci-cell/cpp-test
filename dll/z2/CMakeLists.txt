cmake_minimum_required(VERSION 3.10)
project(lena-gray)

set(CMAKE_CXX_STANDARD 17)

# 设置OpenCV的路径
set(OpenCV_INCLUDE_DIRS "C:/Users/Chai/Desktop/cpp-libs/opencv/build/include")
set(OpenCV_LIBRARIES "C:/Users/Chai/Desktop/cpp-libs/opencv/build/x64/vc16/lib/opencv_world4100d.lib")

add_definitions(-DBUILDING_DLL)

include_directories(${OpenCV_INCLUDE_DIRS})
# 包含头文件目录
include_directories(include)

# 创建 DLL
add_library(lena-gray SHARED src/lena-gray.cpp)

# 链接OpenCV库
target_link_libraries(lena-gray ${OpenCV_LIBRARIES})
# 链接 OpenCV 库
target_link_libraries(lena-gray ${OpenCV_LIBS})
