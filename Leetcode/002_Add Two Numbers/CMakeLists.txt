 #1.cmake verson，指定cmake版本
 cmake_minimum_required(VERSION 3.6)
 #2.project name，指定项目的名称，一般和项目的文件夹名称对应
 PROJECT(Leetcode)
 #3.head file path，头文件目录
 INCLUDE_DIRECTORIES(
    include
 )
 #4.source directory，源文件目录,查找src目录下所有源文件并将名称保存到 DIR_SRCS 变量
 AUX_SOURCE_DIRECTORY(src DIR_SRCS)

 #添加子目录
 #ADD_SUBDIRECTORY(src)

 set(CMAKE_C_STANDARD 11)
 set(CMAKE_COMPILER_IS_GNUCC TRUE)
 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")


 #5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，
 #否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
 SET(APP ${DIR_SRCS})

 #6.设置可执行文件的输出目录
 SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
 #设置DEbug版本可执行文件的
 set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)

 #7.编译成可执行文件
 ADD_EXECUTABLE(${PROJECT_NAME} ${APP})


 #7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
 TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)
