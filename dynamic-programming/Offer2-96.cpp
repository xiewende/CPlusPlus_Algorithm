// 剑指 Offer II 096. 字符串交织

// 解题思路

// dp[i][j]: 代表 s1 的前 i 个和 s2 的前 j 个字符组成 s3 的前 i+j 个是否可以交织来的，
// 状态转移方程

// dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i+j] )  or ( dp[i][j-1] && s2[j-1] == s3[i+j] )


#include<iostream>
#include<vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if(len1 + len2 != len3){
        return false;
    }

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            int idx = i + j;
            if(i>0){
                dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[idx - 1]);
            }
            if(j>0){
                dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[idx - 1]);
            }
        }
    }
    return dp[len1][len2];
}

int main(int argc, char const *argv[])
{

    string s1 = "";
    string s2 = "";
    string s3 = "";
    bool ans = isInterleave(s1, s2, s3);
    cout << ans;
    return 0;
}
