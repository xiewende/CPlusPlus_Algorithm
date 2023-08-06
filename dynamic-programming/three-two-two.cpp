// 322. 零钱兑换

// 解题思路：动态规划，多重背包问题

// dp[i][j]：前i种硬币，拼成j元的最小次数

// 遍历i，j
//         若 j < coins[i] 就是说明当前硬币太大了不配用来凑成j元，此时 dp[i][j] = dp[i - 1][j]; 前一个硬币来凑就好
//         若 j > coins[i],就是这个硬币可以拿来凑j元，有两个选择，一是就不要这个硬币来凑，二是就用这个硬币来
//                         dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i] + 1])

#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_am = amount + 1;
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, max_am));
    dp[0][0] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= amount;j++)
        {
            // 钱不够，不要这个硬币
            if(j<coins[i-1]){
                dp[i][j] = dp[i - 1][j];
            }else{
                // 钱够，就要这个硬币
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amount] == max_am ? -1 : dp[n][amount];
}

// 空间优化
int coinChange1(vector<int>& coins, int amount) {
    int n = coins.size();
    int max_am = amount + 1;
    // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, max_am));
    vector<int> dp(amount + 1, max_am);
    dp[0] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j <= amount;j++)
        {
            // 钱不够，不要这个硬币
            if(j >= coins[i-1]){
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        // for (int j = coins[i-1]; j <= amount; j++) // 完全背包就是顺序，0-1背包就是逆序
        // {
        //     dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
        // }
    }
    return dp[amount] == max_am ? -1 : dp[amount];
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int ans = coinChange1(coins, amount);
    cout << ans;
    return 0;
}

