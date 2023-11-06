#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<utility> // pair
#include<numeric> // accumulate求和


using namespace std;

// 自定义排序方式，也可以排序结构体，多个维度，是什么结构体 cmp 就传什么参数 bool cmp(node a, node b)
// 在定义为 类成员函数 的时候一定需要 static 修饰；
static bool cmp(int a, int b){
    // return a>b; // 降序
    return a < b; // 升序
}

// 优先队列 方法1:
// 按pair的第二个元素降序排列
static bool cmpp(pair<int,int> a, pair<int, int> b){
    return a.second > b.second;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);

// 优先队列 方法2:
struct cmpp1{
    // 别的元素也可以。。。
    bool operator()(pair<int,int> a, pair<int, int> b){
        return a.second > b.second;
}
};
priority_queue<pair<int,int> , vector<pair<int,int>>, cmpp1> q;

int main()
{
    // INT_MAX
    int a = 12;
    cout << a << endl;
    cout << "Hello, world!" << endl;
    // int c = INT_MIN
    int b = 3;
    cout << b + a << endl;

    // 数组的自定义排序
    vector<int> nums{3, 4, 2, 5};
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size();i++)
    {
        cout << nums[i] << " ";
    }

    // 优先队列的自定义排序 
    priority_queue<pair<int,int> , vector<pair<int,int>>, cmpp1> q;
    priority_queue<int> q;//默认是从大到小
    priority_queue<int, vector<int> ,less<int> >q;//从大到小排序
    priority_queue<int, vector<int>, greater<int> >q;//从小到大排序


    int sum = accumulate(nums.begin(), nums.end(), 0); // 库函数求和

    // 求数组最大值最小值 algorithm
    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    // int 转 string
    string as = to_string(1);
    // string 转 int...
    string s = "12";
    int s1 = atoi(s.c_str()); // 更稳妥
    int s2 = stoi(s); // 可能会报错
    cout << s1<< s2;

    string s = "2345";
    int c = 1;
    s[0] = c + '0';
    cout << s;
    //system("pause");

    // 输出几位小数
    double a = 3.14159;
    printf("%.2lf", a); // 2就是小数点几位，向上取整 f：float，lf：double

    // unordered_map 的遍历
    unordered_map<int, int> myummap;
    myummap.emplace(11, 222);  // 字符串就是这个方法
    myummap[00] = 11;
    for (auto iter = myummap.begin(); iter != myummap.end(); ++iter) {
        cout << iter->first << "=" << iter->second << endl;
    }

    int mod = 1e9 + 7;

    int a = 9;
    cout << sizeof(a); // 4，字节数

        // 交换值
    int a = 3;
    int b = 5;
    // 利用+
    // a = a + b;
    // b = a - b;
    // a = a - b;
    // 异化
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    
    
    return 0;
}