// 剑指 Offer II 092. 翻转字符

// 解题思路：动态规划

// dp[i]：表示到下标 i 的时候需要翻转的最小次数

// 状态转移方程：
//     1、遇到 1 时：dp[i] = dp[i-1];
//     2、遇到 0 时：有两种做法可以满足题意，一种是直接将0翻转为1，结果为dp[i - 1] + 1;
//        另外一种是将前面的所有1翻转为0，count记录的是前面1的个数，所以
//        dp[i] = min(dp[i - 1] + 1, count);

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int minFlipsMonoIncr(string s) {
    int len = s.length();
    vector<int> dp(len, 0);
    dp[0] = 0;
    int count = s[0] == '1' ? 1 : 0;
    for (int i = 1; i < len; i++)
    {
        // count = s[i] == 1 ? count + 1 : count;
        if(s[i] == '1'){
            count++;
            dp[i] = dp[i - 1];
        }else{
            dp[i] = min(dp[i - 1] + 1, count);
        }
    }
    return dp[len - 1];
}

int main(){
    string s = "100000001010000";
    int ans = minFlipsMonoIncr(s);
    cout << ans;
    return 0;
}