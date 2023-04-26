// 剑指 Offer II 095. 最长公共子序列

// 动态规划

// dp[i][j]: 表示 text1 以字符 text1[i] 结尾和 text2 以字符 text[j] 结尾的最长相同子序列
// 当 text1[i] == text2[j] 时 dp[i][j] = dp[i-1][j-1] + 1
// 当 text1[i] != text2[j] 时 dp[i][j] = max(dp[i-1][j], dp[i][j-1]), 两个字符串的前一个字符的最大值

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main(int argc, char const *argv[])
{
    string text1 = "abc";
    string text2 = "def";
    int ans = longestCommonSubsequence(text1, text2);
    cout << ans;
    return 0;
}
