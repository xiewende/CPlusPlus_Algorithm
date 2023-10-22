// 1402. 做菜顺序

#include<iostream>
#include<vector>
#include<algorithm>

// 方法一：贪心策略
// 题意知道越大的满意度需要放到最后选择，但是前面可以选择的就是一个问题了，前面若全是正数，则肯定全部最大，但是就是有负数，不一样的。

// 假设 s0，s1，s2，s3，... 以此变大

// 1、肯定可以s3，
// 2、若探讨是否可以选择s2，若满足 s2+2*s3 > s3 即 s2+s3>0 则可以选择s2
// 3、若探讨是都可以选择s1，若满足 s1+2*s2+3*s3 > s2+2*s3 即 s1+s2+s3 > 0，则可以选择s3.
// 所以只需要从大到小遍历数组，若前缀和大于0 就是可以选择该个菜的，答案可以用累加来完成乘法的操作，前缀和的前缀和就是答案。


// 方法2：动态规划

// 将问题看成 从一共 i 到菜中 选择 j 到菜的最大值

// dp[i][j] : 一共 i 道菜，其中选取 j 道菜的最大值，其中 1<j<=i, 类似0-1背包问题

// 当j次选择第i道菜，此时需要在 i-1 道菜中选择 j-1 道菜，则 dp[i][j] = dp[i][j] + j*satisfaction[i]。此时 j<=i
// 当j次不选择第i道菜，此时需要在 i-1 道菜中选择 j 道菜。则 dp[i][j] = dp[i-1][j] 此时 j<i
// 上述情况取最大即可

// 最后的答案需要取 dp[n][x] : n=数组长度， 1<x<=n, 需要在遍历的过程取最大。

using namespace std;

// 贪心的思路
int maxSatisfaction(vector<int>& satisfaction) {
    
    // 先排序
    sort(satisfaction.begin(), satisfaction.end());

    int preSum = 0;
    int ans = 0;

    for (int i = satisfaction.size() - 1; i >= 0;i--)
    {
        // 可拿
        if(preSum+satisfaction[i]>0){
            preSum += satisfaction[i];
            ans += preSum;
        }else{
            // 可以结束了，负数太大了
            break;
        }
    }

    return ans;
}

// 动态规划
int maxSatisfaction(vector<int>& satisfaction) {
    // 先排序
    sort(satisfaction.begin(), satisfaction.end());

    int n = satisfaction.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int res = 0;

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + j * satisfaction[i - 1];
            if(j<i){
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
            res = max(res, dp[i][j]);
        }
    }

    return res;
}