// 5.最长回文子串 

// 动态规划

// dp[i][j]:定义在s中的下标i，j这个闭区间的子字符串是否是回文串，j>i

// 1、i==j，一个字符肯定是回文字符串，  ==》初始化
// 2、下标i与下标j相差为1并且s[i]=s[j]，例如aa，也是字符串
// 3、下标i与下标j相差大于1,若s[i]=s[j],则判断区间【i+1，j-1】是否为回文就行了

#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestPalindrome(string s) {

    int n = s.length();

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // 初始化,i==j时，一个字符肯定是回文
    for (int i = 0; i < n;i++)
    {
        dp[i][i] = true;
    }
    // 一般都是记录这两个值来返回字符串的
    int maxLen = 1;
    int beginIdx = 0;
    for (int i = n-1; i >=0 ;i--)
    {
        for (int j = i+1; j < n; j++)
        {
            if(s[i] == s[j]){
                // 情况1
                if(j-i <= 1){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = dp[i + 1][j - 1]; // 情况2
                }
            }
            if(dp[i][j] && j-i+1>maxLen){
                maxLen = j - i + 1;
                beginIdx = i;
            }
        }
    }
    //
    return s.substr(beginIdx, maxLen);
}

int main(int argc, char const *argv[])
{
    string s = "caa";
    string ans = longestPalindrome(s);
    cout << ans;
    return 0;
}
