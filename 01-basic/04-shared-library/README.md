## Introduction

> Shows a hello world example which first creates and links a shared library. 

The files in this tutorial are below:

```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library$ tree
.
├── CMakeLists.txt
├── include
│   └── shared
│       └── Hello.h
├── README.md
└── src
    ├── main.cxx
    └── shared
        └── Hello.cxx

4 directories, 5 files
```

- [CMakeLists.txt]() - Contains the CMake commands you wish to run
- [Hello.h]() - The header file to include
- [Hello.cxx]() - A source file to compile
- [main.cxx]() - The source file with main

## Concepts

### Adding a Shared Library

The **add_library()** function is used to create a library from some source files. This is called as follows:

```cmake
add_library(hello_library SHARED 
    src/shared/Hello.cxx
)
```

This will be used to create a shared library with the name libhello_library.so with the sources passed to the **add_library()** function.

### Linking a Shared Library

Linking a shared library is the same as linking a static library. When creating your executable use the the **target_link_library()** function to point to your library.

```cmake
add_executable(hello_binary
    src/main.cxx
)

target_link_libraries(hello_binary
    PRIVATE 
        hello_library
)
```

This tells CMake to link the hello_library against the hello_binary executable during link time. It will also propagate any include directories with **PUBLIC** or **INTERFACE** scope from the linked library target.

An example of this being called by the linker is

```console
/usr/bin/c++ CMakeFiles/hello_binary.dir/src/main.cxx.o -o hello_binary -rdynamic libhello_library.so -Wl,-rpath,/home/macwink/Workspace/LearnCMake/01-basic/04-shared-library/build
```

## Building the Example
```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library$ mkdir build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library$ cd build/
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ cmake ..
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
-- Build files have been written to: /home/macwink/Workspace/LearnCMake/01-basic/04-shared-library/build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ make
Scanning dependencies of target hello_library
[ 25%] Building CXX object CMakeFiles/hello_library.dir/src/shared/Hello.cxx.o
[ 50%] Linking CXX shared library libhello_library.so
[ 50%] Built target hello_library
Scanning dependencies of target hello_binary
[ 75%] Building CXX object CMakeFiles/hello_binary.dir/src/main.cxx.o
[100%] Linking CXX executable hello_binary
[100%] Built target hello_binary
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ ./hello_binary 
Hello Shared Library!
```

## TIP::Alias Target
As the name suggests an [alias target](https://cmake.org/cmake/help/v3.0/manual/cmake-buildsystem.7.html#alias-targets) is an alternative name for a target that can be used instead of the real target name in read-only contexts.

```cmake
add_library(hello::library ALIAS hello_library)

add_executable(hello_binary
    src/main.cxx
)

target_link_libraries(hello_binary
    PRIVATE 
        hello::library
)
```

As shown below, this allows you to reference the target using the alias name when linking it against other targets.

## Building the Example Again
```console
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ cmake ..
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
-- Build files have been written to: /home/macwink/Workspace/LearnCMake/01-basic/04-shared-library/build
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ make
Scanning dependencies of target hello_library
[ 25%] Building CXX object CMakeFiles/hello_library.dir/src/shared/Hello.cxx.o
[ 50%] Linking CXX shared library libhello_library.so
[ 50%] Built target hello_library
Scanning dependencies of target hello_binary
[ 75%] Building CXX object CMakeFiles/hello_binary.dir/src/main.cxx.o
[100%] Linking CXX executable hello_binary
[100%] Built target hello_binary
macwink@macwink-Lenovo-Yoga-C940-14IIL:~/Workspace/LearnCMake/01-basic/04-shared-library/build$ ./hello_binary 
Hello Shared Library!
```