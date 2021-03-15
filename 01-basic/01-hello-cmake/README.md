## Introduction

> Shows a very basic hello world example. The files in this tutorial are below:

```
01-hello-cmake$ tree
.
├── CMakeLists.txt
├── main.cxx
└── README.md
```

- [CMakeLists.txt]() - Contains the CMake commands you wish to run.
- [main.cpp]() - A simple "Hello World" cxx file, will lsprintf "Hello macwink! Welcome to the world of CMake!!".

## Concepts

### CMakeLists.txt

> CMakeLists.txt is the file which should store all your CMake commands. When cmake is run in a folder it will look for this file and if it does not exist cmake will exit with an error.

### Minimum CMake version

> When creating a project using CMake, you can specify the minimum version of CMake that is supported.

```cmake
cmake_minimum_required(VERSION 3.10)
```

### Projects

> A CMake build can include a project name to make referencing certain variables easier when using multiple projects.

```cmake
project (hello_cmake)
```

### Creating an Executable

> The +add_executable()+ command specifies that an executable should be build from the specified source files, in this example main.cpp. The first argument to the +add_executable()+ function is the name of the executable to be built, and the second argument is the list of source files to compile.

```cmake
add_executable(hello_cmake main.cpp)
```

### CMakeLists.txt

> A shorthand that some people use is to have the project name and executable name the same. This allows you to specify the CMakeLists.txt as follows,

```cmake
cmake_minimum_required(VERSION 2.6)
project (hello_cmake)
add_executable(${PROJECT_NAME} main.cpp)
```

> In this example, the +project()+ function, will create a variable +${PROJECT_NAME}+ with the value hello_cmake. This can then be passed to the +add_executable()+ function to output a 'hello_cmake' executable.

### Binary Directory

> The root or top level folder that you run the cmake command from is known as your CMAKE_BINARY_DIR and is the root folder for all your binary files. CMake supports building and generating your binary files both in-place and also out-of-source.

#### In-Place Build

> In-place builds generate all temporary build files in the same directory structure as the source code. This means that all Makefiles and object files are interspersed with your normal code. To create an in-place build target run the cmake command in your root directory. 

- For example:

```shell
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ cmake .
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/macwink/Workspace/LearnCMake/01-basic/01-hello-cmake
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ tree
.
├── CMakeCache.txt
├── CMakeFiles
│   ├── 3.10.2
│   │   ├── CMakeCCompiler.cmake
│   │   ├── CMakeCXXCompiler.cmake
│   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   ├── CMakeSystem.cmake
│   │   ├── CompilerIdC
│   │   │   ├── a.out
│   │   │   ├── CMakeCCompilerId.c
│   │   │   └── tmp
│   │   └── CompilerIdCXX
│   │       ├── a.out
│   │       ├── CMakeCXXCompilerId.cpp
│   │       └── tmp
│   ├── cmake.check_cache
│   ├── CMakeDirectoryInformation.cmake
│   ├── CMakeOutput.log
│   ├── CMakeTmp
│   ├── feature_tests.bin
│   ├── feature_tests.c
│   ├── feature_tests.cxx
│   ├── hello_cmake.dir
│   │   ├── build.make
│   │   ├── cmake_clean.cmake
│   │   ├── DependInfo.cmake
│   │   ├── depend.make
│   │   ├── flags.make
│   │   ├── link.txt
│   │   └── progress.make
│   ├── Makefile2
│   ├── Makefile.cmake
│   ├── progress.marks
│   └── TargetDirectories.txt
├── cmake_install.cmake
├── CMakeLists.txt
├── main.cxx
├── Makefile
└── README.md

8 directories, 32 files
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ make
Scanning dependencies of target hello_cmake
[ 50%] Building CXX object CMakeFiles/hello_cmake.dir/main.cxx.o
[100%] Linking CXX executable hello_cmake
[100%] Built target hello_cmake
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ ./hello_cmake 
Hello macwink! Welcome to the world of CMake!!
```
> Terminal Output "Hello macwink! Welcome to the world of CMake!!". 

#### Out-of-Source Build

> Out-of-source builds allow you to create a single build folder that can be anywhere on your file system. All temporary build and object files are located in this directory keeping your source tree clean. To create an out-of-source build run the cmake command in the build folder and point it to the directory with your root CMakeLists.txt file. Using out-of-source builds if you want to recreate your cmake environment from scratch, you only need to delete your build directory and then rerun cmake.

- For example:

```cmake
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ mkdir build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake$ cd build/
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake/build$ cmake ..
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/macwink/Workspace/LearnCMake/01-basic/01-hello-cmake/build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake/build$ tree
.
├── CMakeCache.txt
├── CMakeFiles
│   ├── 3.10.2
│   │   ├── CMakeCCompiler.cmake
│   │   ├── CMakeCXXCompiler.cmake
│   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   ├── CMakeSystem.cmake
│   │   ├── CompilerIdC
│   │   │   ├── a.out
│   │   │   ├── CMakeCCompilerId.c
│   │   │   └── tmp
│   │   └── CompilerIdCXX
│   │       ├── a.out
│   │       ├── CMakeCXXCompilerId.cpp
│   │       └── tmp
│   ├── cmake.check_cache
│   ├── CMakeDirectoryInformation.cmake
│   ├── CMakeOutput.log
│   ├── CMakeTmp
│   ├── feature_tests.bin
│   ├── feature_tests.c
│   ├── feature_tests.cxx
│   ├── hello_cmake.dir
│   │   ├── build.make
│   │   ├── cmake_clean.cmake
│   │   ├── DependInfo.cmake
│   │   ├── depend.make
│   │   ├── flags.make
│   │   ├── link.txt
│   │   └── progress.make
│   ├── Makefile2
│   ├── Makefile.cmake
│   ├── progress.marks
│   └── TargetDirectories.txt
├── cmake_install.cmake
└── Makefile

8 directories, 29 files
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake/build$ make
Scanning dependencies of target hello_cmake
[ 50%] Building CXX object CMakeFiles/hello_cmake.dir/main.cxx.o
[100%] Linking CXX executable hello_cmake
[100%] Built target hello_cmake
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/01-hello-cmake/build$ ./hello_cmake 
Hello macwink! Welcome to the world of CMake!!
```

> Terminal Output "Hello macwink! Welcome to the world of CMake!!". 
