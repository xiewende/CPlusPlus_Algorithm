// 188. 买卖股票的最佳时机 IV

// 解题思路：分状态dp

// 在某一天过后：存在四种状态
// 1、只进行过一次买操作；dp0
// 2、进行了一次买操作和一次卖操作，即完成了一笔交易；dp1
// 3、在完成了一笔交易的前提下，进行了第二次买操作；dp2
// 4、完成了全部两笔交易。dp3
// .
// .
// .
// 2*k个dp就好,轮流执行

// dpX[i]：在四种状态下，在第i天后，所获得的利润是多少！其中 X=0，1，2，3

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    // k * 2 个轮流下来的状态
    vector<vector<int>> dp(k*2, vector<int>(n, 0));
    // 初始化
    for (int i = 0; i < k*2; i++)
    {
        if(i % 2 == 0){
            dp[i][0] = -prices[0];
        }
    }
    // vector<int> dp0(n, 0);
    // vector<int> dp1(n, 0);
    // vector<int> dp2(n, 0);
    // vector<int> dp3(n, 0);
    // 初始化
    // dp0[0] = -prices[0]; // 直接买了第0天的
    // dp1[0] = 0; // 在第0天买了卖了，玩呢，就是0；
    // dp2[0] = -prices[0]; // 在第0天买了卖了，再买，就是亏了第0天的价格；
    // dp3[0] = 0; // 在第0天买了卖了,再买了卖了，真的玩
    // 开始遍历
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k * 2; j++)
        {
            if(j==0){
                dp[j][i] = max(dp[j][i - 1], -prices[i]);
            }else if (j % 2 ==1)
            {
                dp[j][i] = max(dp[j][i-1], dp[j-1][i-1] + prices[i]);
            }else
            {
                dp[j][i] = max(dp[j][i-1], dp[j-1][i-1] - prices[i]);
            }
        }
        // 第 i 天来了，第一次买股票，如何操作
        // dp0[i-1]: 今天的股票贵了，买之前的合适
        // -prices[i]: 今天的股票便宜了，直接买今天的
        //dp0[i] = max(dp0[i-1], -prices[i]);

        // 第 i 天来了，第一次卖股票，如何操作
        // dp1[i-1]: 今天的股市不行，还是卖之前的好
        // dp0[i-1] + prices[i]: 今天股市好哇，直接卖 +prices[i]利润，但是前面刚刚买入的时候利润是 dp0[i-1]
        //dp1[i] = max(dp1[i - 1], dp0[i - 1] + prices[i]);

        // 第 i 天来了，第二次买股票，如何操作
        // dp2[i-1]: 今天的股票贵了，买之前的合适
        // 买今天的股票 利润 -prices[i]; dp1[i - 1]:是第一次卖掉股票时赚的钱
        //dp2[i] = max(dp2[i - 1], dp1[i - 1] - prices[i]);

        // 第 i 天来了，第二次卖股票，如何操作
        // dp3[i-1]: 今天的股市不行，还是卖之前的好
        // dp2[i-1] + prices[i]: 今天股市好哇，直接卖 +prices[i] 利润，但是前面刚刚第二次买入的时候利润是 dp2[i-1]
        //dp3[i] = max(dp3[i-1], dp2[i-1] + prices[i]);
    }

    return dp[2*k-1][n - 1]; //直接返回第二次卖掉的利润
}

// 滚动数组，压缩空间
int maxProfit1(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(2 * k, 0);
    // 初始化
    for (int i = 0; i < k*2; i++)
    {
        if(i % 2 == 0){
            dp[i] = -prices[0];
        }
    }
    int dp0 = -prices[0]; // 直接买了第0天的
    int dp1 = 0; // 在第0天买了卖了，玩呢，就是0；
    int dp2 = -prices[0]; // 在第0天买了卖了，再买，就是亏了第0天的价格；
    int dp3 = 0; // 在第0天买了卖了,再买了卖了，真的玩
    // 开始遍历
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k * 2; j++)
        {
            if(j==0){
                dp[j] = max(dp[j], -prices[i]);
            }else if (j % 2 ==1)
            {
                dp[j] = max(dp[j], dp[j-1] + prices[i]);
            }else
            {
                dp[j] = max(dp[j], dp[j-1] - prices[i]);
            }
        }
        // 第 i 天来了，第一次买股票，如何操作
        // dp0[i-1]: 今天的股票贵了，买之前的合适
        // -prices[i]: 今天的股票便宜了，直接买今天的
        // dp0 = max(dp0, -prices[i]);

        // 第 i 天来了，第一次卖股票，如何操作
        // dp1[i-1]: 今天的股市不行，还是卖之前的好
        // dp0[i-1] + prices[i]: 今天股市好哇，直接卖 +prices[i]利润，但是前面刚刚买入的时候利润是 dp0[i-1]
        // dp1 = max(dp1, dp0 + prices[i]);

        // 第 i 天来了，第二次买股票，如何操作
        // dp2[i-1]: 今天的股票贵了，买之前的合适
        // 买今天的股票 利润 -prices[i]; dp1[i - 1]:是第一次卖掉股票时赚的钱
        // dp2 = max(dp2, dp1 - prices[i]);

        // 第 i 天来了，第二次卖股票，如何操作
        // dp3[i-1]: 今天的股市不行，还是卖之前的好
        // dp2[i-1] + prices[i]: 今天股市好哇，直接卖 +prices[i] 利润，但是前面刚刚第二次买入的时候利润是 dp2[i-1]
        // dp3 = max(dp3, dp2 + prices[i]);
    }

    return dp[2*k-1]; //直接返回第二次卖掉的利润
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    int ans = maxProfit(k, prices);
    cout << ans;
    return 0;
}