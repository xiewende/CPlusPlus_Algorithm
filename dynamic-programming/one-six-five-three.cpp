// 1653 使字符串平衡的最少删除次数
// 解题思路：动态规划
// d[i]: 代表到下边i的时候的字符串最少删除次数，d[n]就是返回的值
// 1、遇到字符 "b",不影响平衡，故 d[i] = d[i-1]
// 2、遇到字符 “a” 第一要么删除 这个 “a” 达到平衡，此时 d[i] = d[i-1] + 1
//                第二要么删除这个位置前面所有字符 “b” 的个数
//                上面两种情况取最小 min 即可

#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

//数组解决
int minimumDeletions(string s) {

    int length = s.length();
    int ans[length+1];
    // memset(ans, 0, sizeof(ans)); //给可变数组赋予赋予初始值
    fill_n(ans, length+1, 10); //首选 前两个参数是指针地址
    int b = 0;
    for (int i = 0; i < length; i++){
        if (s[i] == 'b'){
            ans[i+1] = ans[i];
            b = b + 1;
        }else
        {
            ans[i+1] = min(ans[i] + 1, b);
        }
    }
    return ans[length];
}

// 单个变量解决
int minimumDeletions1(string s) {

    int length = s.length();
    int ans = 0;
    int b = 0;
    for (int i = 0; i < length; i++){
        if (s[i] == 'b'){
            b = b + 1;
        }else
        {
            ans = min(ans+1, b);
        }
    }
    return ans;
}

int main(){

    string s = "aababbab";
    cout << s << endl;
    int ans;
    ans = minimumDeletions(s);
    cout << ans << endl;
    return 0;
}