## Introduction

> Shows a hello world example which uses a different folder for source and include files.

The files in this tutorial include:

```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers$ tree
.
├── CMakeLists.txt
├── include
│   └── Hello.h
├── README.md
└── src
    ├── Hello.cxx
    └── main.cxx

2 directories, 5 files
```

- [CMakeLists.txt]() - Contains the CMake commands you wish to run.
- [include/Hello.h]() - The header file to include.
- [src/Hello.cxx]() - A source file to compile.
- [src/main.cxx]() - The source file with main.

## Concepts

### Directory Paths

> CMake syntax specifies a number of [variables](https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables) which can be used to help find useful directories in your project or source tree. Some of these include:

| __Variable__ | __Info__ |
| :---: | :----: |
| CMAKE_SOURCE_DIR | The root source directory |
|CMAKE_CURRENT_SOURCE_DIR |The current source directory if using sub-projects and directories.|
|PROJECT_SOURCE_DIR |The source directory of the current cmake project.|
|CMAKE_BINARY_DIR |The root binary / build directory. This is the directory where you ran the cmake command.|
|CMAKE_CURRENT_BINARY_DIR |The build directory you are currently in.|
|PROJECT_BINARY_DIR |The build directory for the current project.|

### Source Files Variable

> Creating a variable which includes the source files allows you to be clearer about these files and easily add them to multiple commands, for example, the **add_executable()** function.

```cmake
# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Hello.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
```

| _NOTE_     |  An alternative to setting specific file names in the **SOURCES** variable is to use a GLOB command to find files using wildcard pattern matching.
```cmake
file(GLOB SOURCES "src/*.cpp") 
```
|
| ------------ | --- |

| _TIP_ |For modern CMake it is NOT recommended to use a variable for sources. Instead it is typical to directly declare the sources in the *add_xxx function*. This is particularly important for glob commands which may not always show you the correct results if you add a new source file.|
| ------------ | --- |

### Including Directories

> When you have different include folders, you can make your compiler aware of them using the **target_include_directories()** [function](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html). When compiling this target this will add these directories to the compiler with the -I flag e.g. `-I/directory/path`

```cmake
target_include_directories(target
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
```

> The **PRIVATE** identifier specifies the scope of the include. This is important for libraries and is explained in the next example. More details on the function is available [here](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html).

## Building the Example

### Standard Output

> The standard output from building this example is presented below.

```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers$ mkdir build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers$ cd build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers/build$ cmake ..
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
-- Build files have been written to: /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers/build$ make
Scanning dependencies of target hello_headers
[ 33%] Building CXX object CMakeFiles/hello_headers.dir/src/Hello.cxx.o
[ 66%] Building CXX object CMakeFiles/hello_headers.dir/src/main.cxx.o
[100%] Linking CXX executable hello_headers
[100%] Built target hello_headers
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers/build$ ./hello_headers 
Hello Headers!
```

### Verbose Output
> In the previous examples, when running the make command the output only shows the status of the build. To see the full output for debugging purposes you can add **VERBOSE=1** flag when running make.

> The VERBOSE output is show below, and a examination of the output shows the include directories being added to the c++ compiler command.

```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers/build$ make clean
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/02-hello-headers/build$ make VERBOSE=1
/usr/bin/cmake -H/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers -B/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build --check-build-system CMakeFiles/Makefile.cmake 0
/usr/bin/cmake -E cmake_progress_start /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build/CMakeFiles /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build/CMakeFiles/progress.marks
make -f CMakeFiles/Makefile2 all
make[1]: Entering directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
make -f CMakeFiles/hello_headers.dir/build.make CMakeFiles/hello_headers.dir/depend
make[2]: Entering directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
cd /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build && /usr/bin/cmake -E cmake_depends "Unix Makefiles" /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build/CMakeFiles/hello_headers.dir/DependInfo.cmake --color=
make[2]: Leaving directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
make -f CMakeFiles/hello_headers.dir/build.make CMakeFiles/hello_headers.dir/build
make[2]: Entering directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
[ 33%] Building CXX object CMakeFiles/hello_headers.dir/src/Hello.cxx.o
/usr/bin/c++   -I/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/include   -o CMakeFiles/hello_headers.dir/src/Hello.cxx.o -c /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/src/Hello.cxx
[ 66%] Building CXX object CMakeFiles/hello_headers.dir/src/main.cxx.o
/usr/bin/c++   -I/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/include   -o CMakeFiles/hello_headers.dir/src/main.cxx.o -c /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/src/main.cxx
[100%] Linking CXX executable hello_headers
/usr/bin/cmake -E cmake_link_script CMakeFiles/hello_headers.dir/link.txt --verbose=1
/usr/bin/c++     CMakeFiles/hello_headers.dir/src/Hello.cxx.o CMakeFiles/hello_headers.dir/src/main.cxx.o  -o hello_headers 
make[2]: Leaving directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
[100%] Built target hello_headers
make[1]: Leaving directory '/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build'
/usr/bin/cmake -E cmake_progress_start /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/build/CMakeFiles 0
```

> If you are familiar with gcc and g++ command-line compilation, are you familiar with the following execution process?

```console
[ 33%] Building CXX object CMakeFiles/hello_headers.dir/src/Hello.cxx.o
/usr/bin/c++   -I/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/include   -o CMakeFiles/hello_headers.dir/src/Hello.cxx.o -c /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/src/Hello.cxx
[ 66%] Building CXX object CMakeFiles/hello_headers.dir/src/main.cxx.o
/usr/bin/c++   -I/home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/include   -o CMakeFiles/hello_headers.dir/src/main.cxx.o -c /home/macwink/Workspace/LearnCMake/01-basic/02-hello-headers/src/main.cxx
[100%] Linking CXX executable hello_headers
```
