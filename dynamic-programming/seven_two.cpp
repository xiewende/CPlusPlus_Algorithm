// 72. 编辑距离

// 动态规划

// dp[i][j]：代表在s1中的i位置前和s2的位置j前需要最少操作数

// 状态转移方程：

// 若 s1[i] == s2[j] == > dp[i][j] = dp[i - 1][j - 1]；不需要任何操作
// 若 s1[i] != s2[j] == >  dp[i - 1][j - 1] + 1; 将不同的字符替换即可
//                         dp[i - 1][j] + 1; 删除s1中的字符s1[i]     ； B末尾加
//                         dp[i][j-1] + 1; 在s1的后面添加字符s2[j]   ； A末尾加
//                         三者取最小即可

// 1、
// 对“dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作。”的补充理解：
// 以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：
// (1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]）
// (2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，然后在末尾补充一个 s，即插入操作
// (3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，然后删除 word1 的第 5 个字符



#include<iostream>
#include<vector>

using namespace std;

int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    if(len1*len2==0){
        return len1+len2;
    }

    vector<vector<int>> dp(len1 + 1, vector<int>(len2+1, 0));

    //初始化，s1或者s2为空的时候就是长度
    for (int i = 0; i < len1 + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j < len2 + 1; j++)
    {
        dp[0][j] = j;
    }

    // 开始遍历求其他值
    for (int i = 1; i <= len1;i++)
    {
        for (int j = 1; j <= len2;j++)
        {
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[len1][len2];
}

int main(int argc, char const *argv[])
{
    string s1 = "a";
    string s2 = "ab";
    int ans = minDistance(s1, s2);
    cout << ans;
    return 0;
}
