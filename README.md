```
    _                            _____ __  __       _        
   | |                          / ____|  \/  |     | |       
   | |     ___  __ _ _ __ _ __ | |    | \  / | __ _| | _____ 
   | |    / _ \/ _` | '__| '_ \| |    | |\/| |/ _` | |/ / _ \
   | |___|  __/ (_| | |  | | | | |____| |  | | (_| |   <  __/
   |______\___|\__,_|_|  |_| |_|\_____|_|  |_|\__,_|_|\_\___|
                                                             
```   

## Why prepare this tutorials ？

> Recently, I am doing engineering transformation. Because our project is cross-platform, I think that all the underlying modules are compiled with CMake, and I developed on the Mac, In order to better prepare for this Examples, I specifically talked about the dual system installed on my local machine, which supports Ubuntu 18.04.2.

## Introduction

> CMake is a cross-platform, open-source build system generator.
For full documentation visit the `CMake Home Page`_ and the
`CMake Documentation Page`_. The `CMake Community Wiki`_ also
references useful guides and recipes.

## Environment
- VS Code Version 1.53
- Tree Version 1.7.0
- gcc Version 7.5.0 (c/c++ compiler)
- g++ Version 7.5.0 (c/c++ compiler)
- CMake Version 3.10.2
- GUN Make Version 4.1 Built for x86_64-pc-linux-gnu
- System Ubuntu 18.04.2 GNU/Linux 

Some specific examples may require other tools including:

* [boost](http://www.boost.org/)
```
  $ sudo apt-get install libboost-all-dev
```
* [protobuf](https://github.com/google/protobuf)
```
  $ sudo apt-get install libprotobuf-dev
  $ sudo apt-get install protobuf-compiler
```
* [cppcheck](http://cppcheck.sourceforge.net/)
```
  $ sudo apt-get install cppcheck
```
* [clang](http://clang.llvm.org/)
```
  $ sudo apt-get install clang-3.6
```
* [ninja](https://ninja-build.org/)
```
  $ sudo apt-get install ninja-build
```
* [conan](https://conan.io)
```
  $ sudo apt-get install python3 python3-pip
  $ sudo pip3 install conan
```

## Include

- [concept](https://github.com/imacwink/LearnCMake/tree/master/00-concept) - Mainly include CMake basic grammar learning.
- [basic](https://github.com/imacwink/LearnCMake/tree/master/01-basic) - Basic examples in this directory show how the setup a CMake project.

## Supported Platforms
- Microsoft Windows
- Apple macOS
- Linux
- FreeBSD
- OpenBSD
- Solaris
- AIX
