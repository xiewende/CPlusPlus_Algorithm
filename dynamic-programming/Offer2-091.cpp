// 剑指 Offer II 091. 粉刷房子

// 解题思路：动态规划

// dp[i][j]: 代表粉刷到第 i 个房子的时候，颜色为 j 的最小花费，其中 j=0，1，2 三种颜色
// 状态转移方程

// dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]  i房子刷0号颜色 = i-1号房子 1 和 2 号房子的最小值花费 + i房子刷0号颜色的花费
// dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
// dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]

// 返回 dp[length-1][0],dp[length-1][1],dp[length-1][2] 中的最大值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCost(vector<vector<int>>& costs) {
    int length = costs.size();
    vector<vector<int>> dp(length, vector<int>(3, 0));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < length; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }

    return min(min(dp[length - 1][0], dp[length - 1][1]), dp[length - 1][2]);
}

int main(){
    vector<vector<int>> costs = {{17,2,17}, {16,16,5}, {14,3,19}};
    int ans = minCost(costs);
    cout << ans;
    return 0;
}