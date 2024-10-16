@echo off

REM 设置 Visual Studio 环境
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64

REM 进入项目目录
cd "C:\Users\Chai\Desktop\cpp-test\test\test_z2"

REM 使用 MSBuild 构建项目
msbuild test-z2.sln /p:Configuration=Debug /p:Platform=x64

REM 完成后暂停
pause
