// 122. 买卖股票的最佳时机 II


#include<iostream>
#include<vector>

using namespace std;

// 动态规划1 双重循环
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // dp
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        int curr = 0;
        // 遍历之前的价格，寻找最大值，此时是在i天卖出股票
        for (int j = 0; j < i; j++)
        {
            if(prices[i]>prices[j]){
                curr = max(curr, prices[i] - prices[j] + dp[j]);
            }
        }
        // 在i天 不卖 或者 卖股票 取最大值
        dp[i] = max(dp[i - 1], curr);
    }
    return dp[n - 1];
}

// 动态规划2 单循环，但是需要分状态dp
int maxProfit2(vector<int>& prices) {
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
        dp_0[i] = max(dp_0[i-1], dp_1[i-1] + prices[i]);
        // 第i天持有彩票：前一天就是有彩票 和 今天刚刚把彩票买入了
        dp_1[i] = max(dp_1[i-1], dp_0[i-1] - prices[i]);
    }
    return dp_0[n - 1]; // 返回不持有彩票是最佳的
}


// 贪心算法  
int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    // dp
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        // 只要后一个价格大于前一个价格就买入和卖出，局部最优导致全局最优
        if(prices[i]>prices[i-1]){
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7,6,4,3,1};
    int ans = maxProfit1(prices);
    cout << ans;
    return 0;
}
