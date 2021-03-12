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
- [main.cpp]() - A simple "Hello World" cxx file.

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

