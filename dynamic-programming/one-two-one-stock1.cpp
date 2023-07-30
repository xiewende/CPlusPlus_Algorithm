// 121. 买卖股票的最佳时机

// 解题思路：动态规划 

// 动态规划：
// dp[i]: 以prices[i]结尾的股票收益是多大

// 遇到 prices[i]时候，不卖股票 dp[i] = dp[i-1]
//                     卖股票  dp[i] = prices[i]-minPrices

// 无非就是求最大值和最小值的差异，但是这里必须满足 最大值在最小值的右边，一次遍历就好

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n, 0);
    int minPrices = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrices = min(minPrices, prices[i]);
        dp[i] = max(dp[i - 1], prices[i] - minPrices);
    }
    return dp[n - 1];
}

int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    // vector<int> dp(n, 0);
    int minPrices = prices[0];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        minPrices = min(minPrices, prices[i]);
        // dp[i] = max(dp[i - 1], prices[i] - minPrices);
        ans = max(ans, prices[i] - minPrices);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout << ans;
    return 0;
}

