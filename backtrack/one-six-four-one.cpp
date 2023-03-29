// 1641. 统计字典序元音字符串的数目

// 解题思路

// 1、直接回溯法求解，看 模板即可

// 2、动态规划： 0，1，2，3，4 代表元音字符
// 设 dp[i][j] 表示长度为 i ，以 j 结尾的按字典排序的字符串数量， 初始全为0
// 转移方程： 当 i=1 时，dp[i][j] = 1
//           当 i>1 时，dp[i][j] = dp[i-1][k]+..+dp[i-1][k+1](累加) k=[0,..j]
//           实现，3层循环
// 因此长度为 n 的按字典排序的字符串数量为 dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]
// 因为 dp[i] 的计算只涉及 dp[i-1]的部分数据，同时 dp[i] 等价于 dp[i-1] 的前缀和，所以我们可以只使用1维数组进行存储，同时在1维数组进行原地修改        

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

// 回溯
void backtrack(int n, int len, int index, int &ans){
    if(len == n){
        ans++;
        return;
    }
    for (int i = index; i < 5; i++)
    {
        backtrack(n, len + 1, i, ans);
    }
    return ;
}
int countVowelStrings(int n) {
    int len = 0;
    int index = 0;
    int ans = 0;
    backtrack(n, len, index, ans);
    return ans;
}

// 动态规划
int countVowelStrings1(int n) {

    vector<vector<int>> dp(n+1, vector<int>(5, 0));
    // 长度为1，以任何字母结尾都是1
    for (int i = 0; i < 5;i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0]; // a结尾，更短的时候前面只能是a
        for (int j = 1; j < 5; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; // b结尾，更短的时候前面可以是b，一样长的时候可以是a
        }
        // dp[i][j] = sum;
    }

    return accumulate(dp[n].begin(), dp[n].end(), 0); // 一维数组求和
}

// 动态规划的空间优化
int countVowelStrings(int n) {
    vector<int> dp(5, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < 5; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return accumulate(dp.begin(), dp.end(), 0); // 一维数组求和
}




int main(){
    int n = 2;
    int ans = countVowelStrings1(n);
    cout << ans;
    // test(n);
    // cout << n;
}
