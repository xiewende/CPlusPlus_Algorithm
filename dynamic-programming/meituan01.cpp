//  01 串的权值为：每次操作选择一位取反，使得相邻字符都不相等的最小操作次数。
//  "10001"的权值是 1，因为只需要修改一次：对第三个字符取反即可。
// 输入：
//  10001,
// 输出： 
//  8
// 解释：
// 长度为 2 的子串中，有 2 个"00"的权值是 1。
// 长度为 3 的 3 个子串权值都是 1。
// 长度为 4 的 2 个子串权值都是 1。
// 长度为 5 的 1 个子串权值是 1。
// 总权值之和为 2+3+2+1=8

// 定义dp[i][0], 字串以i位置结尾的 并且以0结尾的字串最小操作次数
// 定义dp[i][1], 字串以i位置结尾的 并且以1结尾的字串最小操作次数

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minOps(string s){
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(2));
    long long sum = 0;
    for (int i = 0; i < n;i++)
    {
        // 判断一个字符的结尾
        if(s[i] == '0'){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }else{
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        // 一步一步判断字串的最小操作数
        for (int j = i + 1; j < n;j++)
        {
            if(s[j] == '0'){
                dp[j][0] = dp[j-1][1];
                dp[j][1] = dp[j-1][0] + 1;
            }else{
                dp[j][0] = dp[j-1][1] + 1;
                dp[j][1] = dp[j-1][0];
            }
            sum += min(dp[j][0], dp[j][1]);
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int ans = minOps(s);
    cout << ans;
    return 0;
}
