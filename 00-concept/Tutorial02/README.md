## Tutorial02

### 环境
- iOS SDK Version 14.0
- Xcode Version 12.0 beta (12A6159)

### 工程目录
```
.
├── CMakeLists.txt
├── Math
│   ├── CMakeLists.txt
│   ├── Math.h
│   └── mysqrt.cxx
├── Tutorial02Config.h.in
└── Tutorial02.cxx
```
### 基础语法

- ADD_SUBDIRECTORY

    语法：
    ```cmake
    ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
    ```
    用于向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置。

    EXCLUDE_FROM_ALL参数的含义是将这个目录从编译过程中排除，比如，工程的 example，可能需要工程构建完成之后，再进入 example 目录单独进行构建。

我们接下来工程中的例子定义了将 Math 目录加入工程，并未指定编译输出路径，则默认输出到根目录。

**如果想换个地方保存目标二进制**

我们可以通过 SET 指令重新定义 EXECUTABLE_OUTPUT_PATH 和 LIBRARY_OUTPUT_PATH 变量，来指定最终的目标二进制的位置 (指最终生成的 Tutorial02 或者最终的共享库，不包含编译生成的中间文件)

```cmake
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_PATH}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_PATH}/lib)
```

上面两个指令分别定义了：可执行二进制的输出路径为 project/bin 和库的输出路径为 project/lib。

至于将这两条指令写在工程的 CMakeLists 中还是 Math 目录下的 CMakeList，只需要按照一个原则：在哪里ADD_EXECUTABLE 或 ADD_LIBRARY，如果需要改变目标存放的路径，就在其上加入上述定义。

- ADD_LIBRARY

    主要包含静态库与动态库的创建，命令如下：

    语法：
    ```cmake
    ADD_LIBRARY( [STATIC | SHARED | MODULE]
                [EXCLUDE_FROM_ALL]
                source1 source2 ... sourceN)
    ```

    类型有三种：

        SHARED : 动态库
        STATIC : 静态库
        MODULE : 在使用 dyld 的系统有效，如果不支持 dyld，则被当作 SHARED 对待
    
    EXCLUDE_FROM_ALL 参数的意思是这个库不会被默认构建，除非有其他的组建依赖或者手工构建

**名字相同的动态库和静态库同时存在**

在同一个 CMake 中，如果 ADD_LIBRARY 的 target 名称相同，则后一个目标会覆盖前一个目标。如果我们想让名字相同的静态库和动态库同时存在，需要用到另外一个命令：

```cmake
SET_TARGET_PROPERTIES(target1 target2 ...
                      PROPERTIES prop1 value1
                      prop2 value2 ...)
```

这条指令可以用来设置输出的名称，对于动态库，还可以用来指定动态库版本和 API 版本。

只需要在 CMakeLists.txt 中加如 SET_TARGET_PROPERTIES(XXX_static PROPERTIES OUTPUT_NAME "XXX")，就可以同时得到 libXXX.a/libXXX.so 两个库了。

**动态库版本号**

为了实现动态库版本号，我们仍然需要使用 SET_TARGET_PROPERTIES 指令。具体使用方法：

```cmake
SET_TARGET_PROPERTIES(XXX PROPERTIES VERSION 1.2 SOVERSION 1)
```

VERSION 指代动态库版本，SOVERSION 指代 API 版本。

假如 CMakeLists 重新构建，在目录下会生成：

```cmake
libXXX.so.1.2
libXXX.so.1->libXXX.so.1.2
libXXX.so ->libXXX.so.1
```

- TARGET_LINK_LIBRARIES

    语法：
    ```cmake
    TARGET_LINK_LIBRARIES(target library1
                            library2
                            ...)
    ```

    这个指令可以用来为 target 添加需要链接的共享库，本例中是一个可执行文件，但是同样可以用于为自己编写的共享库添加共享库链接。

如果我们是Linux环境的话，实际上我们可以通过LDD来检查一下可执行文件的的链接情况，例如我们可以在命令行中输入 ldd Tutorial02，但是如果是 MAC 环境，ldd 就不能使用了，但是我们可以采用 otool 来代替 ldd 的功能。

```cmake
iMacwinkMacBook-Pro:Tutorial02 macwink$ otool -L Tutorial02
Tutorial02:
	/usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 904.4.0)
	/usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1291.0.0)
```