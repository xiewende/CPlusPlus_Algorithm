# CPlusPlus_Algorithm
a code repository implementing common algorithms in C++

## environment of VScode to Run C++/C

- ./vscode x下的四个文件
    - setting.json: 相关code-runner设置 中的指定采用code-runner运行方式；运行指令默认使用g++，勿用clang++
        - 搭配 g++  --target=x86_64-w64-mingw（不要）
        - 搭配 clang++ --target=x86_64-w64-mingw（要）
    - tasks.json：设定F5的启动方式，
    - lunch.json: 设定GBD的启动方式
    - c_cpp_properties.json: 设定编辑器的路劲

- 要想使用STL库：-std=c++20,-std=c++2a (c++11 c++14 不可以编译)
- -Wall 是否忽略warning