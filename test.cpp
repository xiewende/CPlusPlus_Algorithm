#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 自定义排序方式，也可以排序结构体，多个维度
// 在定义为 类成员函数 的时候一定需要 static 修饰；
bool cmp(int a, int b){
    // return a>b; // 降序
    return a < b; // 升序
}

int main()
{
    int a = 12;
    cout << a << endl;
    cout << "Hello, world!" << endl;

    int b = 3;
    cout << b + a << endl;

    vector<int> nums{3, 4, 2, 5};
    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < nums.size();i++)
    {
        cout << nums[i] << " ";
    }

    //system("pause");
    return 0;
}