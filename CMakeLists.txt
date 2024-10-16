cmake_minimum_required(VERSION 3.10)  # 指定CMake的最低版本
project(MyProject)  # 项目名称

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)  # 或者 14、17，根据需要设置

# 设置OpenCV的路径
set(OpenCV_INCLUDE_DIRS "C:/Users/Chai/Desktop/cpp-libs/opencv/build/include")
set(OpenCV_LIBRARIES "C:/Users/Chai/Desktop/cpp-libs/opencv/build/x64/vc16/lib/opencv_world4100d.lib")

# 包含OpenCV头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(main main.cpp)

# 链接OpenCV库
target_link_libraries(main ${OpenCV_LIBRARIES})

# 设置编译选项
target_compile_options(main PRIVATE /EHsc /MDd)  # 选项可以根据需要添加
