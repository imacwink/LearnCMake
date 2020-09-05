## Tutorial01

### 基本语法

一个 CMakeLists 文件至少需要包含以下三行代码：

```cmake
cmake_minimum_required (VERSION x.x)
project (PROJNANME)
add_executable(PROJNANME PROJNANME.cxx)
```

注意：cmake 语法静态检查支持大写、小写和大小写混合，上边的书写方式我们采用的是小写.

```cmake
cmake_minimum_required
CMAKE_MINIMUM_REQUIRED
cmake_MINUMUM_required
```

以上三种写法是相同的，但是一定要注意，只有系统指令是不区分大小写的，但是变量和字符串是区分大小写的。

### 语法解析
> cmake 的函数可以通过 cmake --help-command cmd 来查看具体的语法及使用方法

- PROJECT

    语法：
    ```python3
    project( [languageName1 languageName2 ... ] )
    ```
    设置项目名称并可指定工程支持的语言，支持的语言列表是可以忽略的，默认情况表示支持所有语言。这个指令隐式的定义了两个 cmake 变量:

    ```c
    - <projectname>_BINARY_DIR
    - <projectname>_SOURCE_DIR
    ```

    因为采用的是内部编译，两个变量目前指的都是工程所在路径 /Users/macwink/workspace/work/crossplatform/LearnCMake/Tutorial01，后面我们会讲到外部编译，两者所指代的内容会有所不同。

    同时 cmake 系统也帮助我们预定义了 PROJECT_BINARY_DIR 和 PROJECT_SOURCE_DIR
    变量，他们的值分别跟 <projectname>_BINARY_DIR 与 <projectname>_SOURCE_DIR 一致。

    为了统一起见，建议以后直接使用 PROJECT_BINARY_DIR，PROJECT_SOURCE_DIR，即
    使修改了工程名称，也不会影响这两个变量。如果使用了
    <projectname>_SOURCE_DIR，修改工程名称后，需要同时修改这些变量。
    <br>
- SET

    语法：
    ```python3
    SET( 
      [[CACHE   [FORCE]] | PARENT_SCOPE])
    ```
    在初探阶段，我们只需要知道 SET 命令可以用来显示的定义一个变量。<br>
    比如在这个例子中 SET(Tutorial01_VERSION_MAJOR 1) &  set (Tutorial01_VERSION_MINOR 0)，即定义了两个变量 Tutorial01_VERSION_MAJOR & Tutorial01_VERSION_MINOR 应用与定义版本。

### 准备 CMakeLists 文件

```c++
cmake_minimum_required (VERSION 2.6)
project (Tutorial01)

# The version number.
 set (Tutorial01_VERSION_MAJOR 1)
 set (Tutorial01_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
 configure_file (
   "${PROJECT_SOURCE_DIR}/Tutorial01Config.h.in"
   "${PROJECT_BINARY_DIR}/Tutorial01Config.h"
   )

# add the binary tree to the search path for include files
# so that we will find Tutorial01Config.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(Tutorial01 Tutorial01.cxx)
```

### 准备程序源文件

创建一个 Tutorial.cxx 文件，用来计算一个数字的平方根，内容如下:

```c++
// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (int argc, char *argv[])
{
    if (argc < 2) // 入参小于 2 打印参数数值
    {
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }
    
    double inputValue = atof(argv[1]);
    double outputValue = sqrt(inputValue);
    fprintf(stdout,"The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}
```

如上你就完成一个最简单的 cmake 程序。

### 构建程序

用 cmake 来编译上面的求平方根代码，进入命令行执行内部构建命令：

```cmake
cmake .
```

命令行输出如下：

```c
-- The C compiler identification is AppleClang 12.0.0.12000022
-- The CXX compiler identification is AppleClang 12.0.0.12000022
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/macwink/workspace/work/crossplatform/LearnCMake/Tutorial01
```

同时生成了三个文件 CMakeCache.txt、Makefile、cmake_install.cmake 和一个文件夹 CmakeFiles, 其实我们只需要关心 Makefile 文件就可以了，首先理解一下它的作用。

#### Makefile
> makefile 文件和 make 工具一起使用，用于控制工程项目的编译和链接，也可以用来编写手册页和程序的安装。make 工具用于解释执行 makefile 文件中的内容。makefile 文件中通常包含源文件和目标文件的依赖关系以及从源文件生成目标文件的规则。make 工具可以根据 makefile 判断哪些文件需要被重新编译，目标文件的构建顺序等。

命令行执行 make 操作

```
make
```

输出结果如下：

```c
Scanning dependencies of target Tutorial01
[ 50%] Building CXX object CMakeFiles/Tutorial01.dir/Tutorial01.cxx.o
[100%] Linking CXX executable Tutorial01
[100%] Built target Tutorial01
```

我们得到了可执行文件 Tutorial01，在命令行执行：

```
./Tutorial01
```

输出结果如下：

```c
./Tutorial01 Version 1.0
Usage: ./Tutorial01 number
```

命令行尝试执行 ./Tutorial01 4

```
./Tutorial01 4
```

输出结果如下：

```c
The square root of 4 is 2
```



