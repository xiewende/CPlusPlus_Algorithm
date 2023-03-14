# CPlusPlus_Algorithm
A code repository implementing common algorithms in C++.

This is a repository that implements the algorithms in LeetCode. We divide the files according to the algorithm type, and the cpp file name is the serial-number of the corresponding LeetCode topic.

## environment of VScode to Run C++/C

- The Best Attentioned 

    [解题总结链接](https://github.com/xiewende/CPlusPlus_Algorithm/blob/main/problem-solving-template.md)  ,   [个人主页](https://sevenboy.online/)


- 下载 C/C++ 环境
    - 下载 [LLVM Download](https://releases.llvm.org/download.html)，在此页面下载Clang。选 Pre-Built Binaries 中的 Windows (64-bit)，不需要下.sig文件
    - 下载 [MinGW-w64-for 32 and 64 bit Windows](https://sourceforge.net/projects/mingw-w64/files/)，在此页面下载 MinGW-w64，往下稍微翻一下，选最新版本中的x86_64-posix-seh。最好不要用 Download Latest Version，这个是在线安装包，有可能因为国内的“网络环境”下载失败。如果浏览器还是下载失败就换迅雷下，还失败，那就使用能访问Google的那种方法下。
    - 安装Clang：添加环境变量时，选 Add LLVM to the system PATH for all users（即第二项，不过第三项也差不多）；路径我填的是 C:\LLVM，也可以保持默认或者自己改。
    - 安装MinGW-w64：下下来的是一个7z的压缩包，随便解压到哪，把东西全部复制（或者直接剪切）到 Clang 的文件夹里去（除非你有自己的想法），它们会无冲突合并，然后就可以把它删了。
    - 验证环境： cmd 中输入 clang -v 或 gcc -v，有环境即可  

- 配置./vscode x下的四个文件
    - setting.json: 相关code-runner设置 中的指定采用code-runner运行方式；运行指令默认使用g++，勿用clang++
        - 搭配 g++  --target=x86_64-w64-mingw（不要）
        - 搭配 clang++ --target=x86_64-w64-mingw（要）
    - tasks.json：设定F5的启动方式，
    - lunch.json: 设定GBD的启动方式
    - c_cpp_properties.json: 设定编辑器的路劲

- 要想使用STL库：-std=c++20,-std=c++2a (c++11 c++14 不可以编译)
- -Wall 是否忽略warning