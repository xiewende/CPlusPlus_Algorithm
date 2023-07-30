#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#include<numeric> // accumulate求和

using namespace std;

// 1、cin
//     cin可以连续从键盘读入数据
//     cin以空格、tab、换行符作为分隔符
//     cin从第一个非空格字符开始读取，直到遇到分隔符结束读取
//     int num
//     cin>>num  先定义再输入
// 2、getline
//     从cin的注意中，也可以看出，当我们要求读取的字符串中间存在空格的时候，cin会读取不全整个字符串，这个时候，可以采用getline()函数来解决。
//     使用getline()函数的时候，需要包含头文件
//     getline()函数会读取一行，读取的字符串包括空格，遇到换行符结束
//     string s
//     getline(cin, s)
// 3、getchar()
//     该函数会从缓存区中读出一个字符，经常被用于判断是否换行

int main()
{
    // 1、一维数组：固定数组个数
    int n;
    cin >> n; // 读入3，说明数组的大小是3
    vector<int> nums(n); // 创建大小为 3 的 vector<int>
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 2、一维数组：不固定数组个数
    // 输入的数据用空格间隔的整数组成的数组，一行输入
    // 输入格式：
    // 1 2 3 4
    // while 结合 cin 解决
    // vector<int> nums;
    int num; //记录每个数字
    while(cin>>num){
        nums.emplace_back(num); // 添加到数组
        // 读到换行符，终止循环读入
        if(getchar() == '\n'){
            break;
        }
    }

    // 3、二维数组；常规模式
    // 输入格式：
    // 2 3
    // 1 2 3
    // 1 2 3
    // 第一行的2，代表数据为2行，3代表数据为3列，因此根据第一行，可以得出，所输入数据为2行3列的二维数组。
    // 接下来的6个数字，就是按照空格和换行符分隔开的2x3二维数组，因此用for循环和cin即可处理
    int m; // 接收行数
    int n; // 接收列数
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 4、二维数组：每一行数据是逗号隔开的整数
    // 输入格式：
    // 2 3
    // 1，2，3
    // 1，2，3
    // 第一行的2，代表数据为2行，3代表数据为3列，因此根据第一行，可以得出，所输入数据为2行3列的二维数组。
    // 接下来的2行，分别是一个字符串，字符串中用逗号隔开每个整数。这里采用读入字符串的方式，并将读入的字符串进行按逗号分开。
    int m; // 接收行数
    int n; // 接收列数
    cin >> m >> n;
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) {
        // 读入字符串
        string s;
        getline(cin, s);
        // 将读入的字符串按照逗号分隔为vector<int>
        vector<int> vec;
        int p = 0;
        for (int q = 0; q < s.size(); q++) {
            p = q;
            while (s[p] != ',' && p < s.size()) {
                p++;
            }
            string tmp = s.substr(q, p - q);
            vec.push_back(stoi(tmp));
            q = p;
        }
        //写入matrix
        matrix[i] = vec;
        vec.clear();
    }

    // 5、字符串：单字符串
    // 输入格式：
    // abc
    string s;
    cin >> s;

    // 6、给定数目多字符串
    // 输入格式：
    // 3 abc ab a
    // 第一行的3，代表有3个字符串，后续为用空格隔开的3个字符串，采用for循环和cin读入即可
    int n;
    cin >> n; // 读入3，说明字符串数组的大小是3
    vector<string> strings(n); // 创建大小为3的vector<string>
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    // 7、不给定数目多字符串
    // 输入格式
    // abc ab a b
    // 输入为用空格隔开的若干个字符串。
    vector<string> strings;
    string str;
    while (cin >> str) {
        strings.push_back(str);
        // 读到换行符，终止循环
        if (getchar() == '\n') {
            break;
        }
    }

    // 字符串转整数数组
    // 输入格式：
    // 11，22，3，4
    // 输入为一个完整字符串，字符串内容是按照逗号隔开的一个数组，可以先读入完成字符串，然后根据逗号进行分隔
    vector<int> vec;
    // 读入字符串
    string s;
    getline(cin, s);

    // 将读入的字符串按照逗号分隔为vector<int>
    int p = 0;
    for (int q = 0; q < s.size(); q++) {
        p = q;
        while (s[p] != ',' && p < s.size()) {
            p++;
        }
        string tmp = s.substr(q, p - q);
        // cout << tmp;
        vec.push_back(stoi(tmp));
        q = p;
    }

    return 0;
}