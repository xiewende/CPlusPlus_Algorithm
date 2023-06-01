// 剑指 Offer II 103. 最少的硬币数目
// 动态规划，多重背包问题

#include<iostream>
#include<vector>

using namespace std;

// 空间没有优化
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_count = amount + 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, max_count));
    dp[0][0] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= amount;j++)
        {
            // 钱不够，直接不选取这个硬币
            if(j<coins[i-1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                // 钱够，选取或者不选取该硬币，选最小
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i-1]] + 1);
            }
        }
    }

    return dp[n][amount] == max_count ? -1 :dp[n][amount];
}

// 空间优化
int coinChange1(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_count = amount + 1; //INT_MAX/2
    // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX/2));
    vector<int> dp(amount + 1, max_count);
    dp[0] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = coins[i-1]; j <= amount; j++) // 完全背包就是顺序，0-1背包就是逆序
        {
            dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
        }
    }
    return dp[amount] == max_count ? -1 :dp[amount];
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout << ans;
    return 0;
}
