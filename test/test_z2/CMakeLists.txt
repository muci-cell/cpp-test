cmake_minimum_required(VERSION 3.10)
project(test-z2)

set(CMAKE_CXX_STANDARD 17)

# 设置OpenCV的路径
set(OpenCV_INCLUDE_DIRS "C:/Users/Chai/Desktop/cpp-libs/opencv/build/include")
set(OpenCV_LIBRARIES "C:/Users/Chai/Desktop/cpp-libs/opencv/build/x64/vc16/lib/opencv_world4100d.lib")

# add_definitions(-DBUILDING_DLL)
# 添加可执行文件
add_executable(test-z2 src/test_z2.cpp)

# 为目标添加头文件目录
target_include_directories(test-z2 PRIVATE 
    "C:/Users/Chai/Desktop/cpp-test/dll/z2/include" 
    ${OpenCV_INCLUDE_DIRS}
)
# 链接OpenCV库和自定义的DLL对应的.lib文件
target_link_libraries(test-z2 
    ${OpenCV_LIBRARIES} 
    "C:/Users/Chai/Desktop/cpp-test/dll/z2/Debug/lena-gray.lib"
)
