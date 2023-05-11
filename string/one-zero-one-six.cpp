// 1016. 子串能表示从 1 到 N 数字的二进制串

// 解题思路

// 1、将【1，n】逐个转为2进制数，判断是否在s中

// 2、将 s 中字串转为十进制数，判断是不是小于 n，不过这里有优化，0开头的不用计算，超过n的不要，最后判断生成的个数是不是和n相等

#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;


string getSecond(int n){
    string ans = "";
    while(n!=0){
        int redis = n % 2;
        n = n / 2;
        ans = to_string(redis) + ans;
    }
    return ans;
}

bool queryString(string s, int n) {
    for (int i = 1; i <= n;i++)
    {
        string second = getSecond(i);
        int index = s.find(second);
        if(index >= s.length()){
            return false;
        }
    }
    return true;
}


bool queryString1(string s, int n) {
    unordered_set<int> seen;
    for (int i = 0, m = s.length(); i < m; ++i) {
        int x = s[i] - '0';
        if (x == 0) continue; // 二进制数从 1 开始
        for (int j = i + 1; x <= n; j++) {
            seen.insert(x);
            if (j == m) break;
            x = (x << 1) | (s[j] - '0'); // 子串 [i,j] 的二进制数
        }
    }
    return seen.size() == n;
}


int main(int argc, char const *argv[])
{
    string s = "0110";
    int n = 4;
    // string ans = getSecond(n);
    bool ans = queryString(s, n);
    // cout << ans;
    int a = (3 << 1) | 0;
    cout << a;
    return 0;
}
