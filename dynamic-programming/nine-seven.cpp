// 97. 交错字符串

// dp[i][j]：定义s1的前i个字符 和 s2的前j个字符 是否可以组成 s3的前 i+j 个字符。

// s1：i，s2：j，s3：p = i+j-1  下标

// 若 s1[i]==s3[p], 则 dp[i][j] = dp[i-1][j]
// 若 s2[j]==s3[p]，则 dp[i][j] = dp[i][j-1]

// 初始化：dp[0][0] = true, 都没有字符设定为true；

// 返回 dp[n1][n2] 即可

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.length();
    int n2 = s2.length();

    if(n1 + n2 != s3.length()){
        return false;
    }

    vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
    // 初始化
    dp[0][0] = true;
    // 单单看s1能不能变为s3
    for (int i = 1; i <= n1;i++)
    {
        if(s1[i-1] != s3[i-1]){
            break;
        }
        dp[i][0] = true;
    }
    // 单单看s2能不能变为s3
    for (int j = 1; j <= n2;j++)
    {
        if(s2[j-1] != s3[j-1]){
            break;
        }
        dp[0][j] = true;
    }

    // 遍历递归
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            int p = i + j - 1;
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[p]) || (dp[i][j - 1] && s2[j - 1] == s3[p]);
        }
    }

    return dp[n1][n2];
}

int main(int argc, char const *argv[])
{
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool ans = isInterleave(s1, s2, s3);
    cout << ans;
    return 0;
}
