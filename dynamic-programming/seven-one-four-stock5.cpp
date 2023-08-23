// 714. 买卖股票的最佳时机含手续费

// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了

#include<iostream>
#include<vector>

using namespace std;


// 动态规划2 单循环，但是需要分状态dp
int maxProfit2(vector<int>& prices, int free) {
    int n = prices.size();
    // dp
    vector<int> dp_0(n, 0); //表示底i天手里没有股票的最大利润
    vector<int> dp_1(n, 0); //表示底i天手里有股票的最大利润
    // 初始化
    dp_0[0] = 0;
    dp_1[0] = -prices[0];//第0天有股票说明就是入手了，这边直接就是负利润。
    // 循环
    for (int i = 1; i < n; i++)
    {
        // 第i天没有彩票：前一天就是没有彩票 和 今天刚刚把彩票卖了
        dp_0[i] = max(dp_0[i-1], dp_1[i-1] + prices[i] - free);
        // 第i天持有彩票：前一天就是有彩票 和 今天刚刚把彩票买入了
        dp_1[i] = max(dp_1[i-1], dp_0[i-1] - prices[i]);
    }
    return dp_0[n - 1]; // 返回不持有彩票是最佳的
}

// 贪心算法
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int buy = prices[0] + fee;
    int profit = 0;
    for (int i = 1; i < n; ++i) {
        if (prices[i] + fee < buy) {
            buy = prices[i] + fee;
        }
        else if (prices[i] > buy) {
            profit += prices[i] - buy;
            buy = prices[i];
        }
    }
    return profit;
}



int main(int argc, char const *argv[])
{
    vector<int> prices = {1,3,7,5,10,3};
    int free = 3;
    int ans = maxProfit2(prices, free);
    cout << ans;
    return 0;
}
