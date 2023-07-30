// 309. 最佳买卖股票时机含冷冻期

// # 动态规划 两个状态

// dp0[i]: 手里没有股票的时候第i天的利润
// dp1[i]：手里有股票的时候第i天的利润

// 初始化：
// dp0[0] = 0
// dp1[0] = -price[0]

// 状态转移方程

// dp0[i] = max(dp0[i-1], dp1[i-1]+prices[i]) 前一天就是没有股票在手；今天刚刚卖出去股票

// dp1[i] = max(dp1[i-1], dp0[i-2]-prices[i]) 前一天就是有股票在手；今天买入股票，因为有冷冻期，不可以前一天的时候没有股票买，而是冷冻期的前一天，冷冻期就是隔一天

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp0(n, 0); // 手里没有股票时候的利润
    vector<int> dp1(n, 0); // 手里有股票的利润
    // 初始化
    dp0[0] = 0;
    dp1[0] = -prices[0];

    // dp0[1] = max(dp0[0], dp1[0] + prices[1]);
    // dp1[1] = max(dp1[0],-prices[1]);

    for (int i = 1; i < n;i++)
    {
        dp0[i] = max(dp0[i - 1], dp1[i - 1] + prices[i]);
        if(i==1){
            dp1[i] = max(dp1[i - 1], -prices[i]);
        }else
        {
            dp1[i] = max(dp1[i - 1], dp0[i - 2] - prices[i]);
        }
    }
    return dp0[n-1];
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {1};
    int profit = maxProfit(prices);
    cout << profit;
    return 0;
}

