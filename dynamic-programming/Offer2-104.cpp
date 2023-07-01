// 剑指 Offer II 104. 排列的数目

// 解题思路：动态规划，完全背包问题, 但是需要排序的问题

// 状态转移方程：dp[j] = dp[j] + dp[j-nums[i]] （都是一样的）  dp[0] = 1:题意

// 外循环若是nums，内循环是target 则是完全背包中的组合问题，考虑到组合问题（3，1）（1，3）是一样的
// 外循环若是target，内循环是nums 则是完全背包中的组合问题，考虑到排序问题（3，1）（1，3）是不一样的

// 所以控制完全背包中的内外层循环顺序即可。都是小到大排序

// 但是0-1背包中，
// 外循环若是nums，内循环是target，但是内循环需要从大到小

// 0-1背包中二维dp数组的两个for遍历的先后循序是可以颠倒
// 一维dp数组的两个for循环先后循序一定是先遍历物品，再遍历背包容量。

// 在完全背包中，不论空间是二维，还是优化为一维，两个for循环嵌套顺序同样无所谓！就是组合和排序的问题了

#include<iostream>
#include<vector>

using namespace std;

// 二维DP
int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int j = 0; j <= target; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            // 当前金额都大于所需要凑成的金额了,肯定不用当前nums[i]
            if(nums[i-1]>j){
                dp[i][j] = dp[i - 1][j];
            }else{
                // 可以装下，可以选择 拿或者不拿  只是将 0-1背包问题中的 i-1 改为 i
                dp[i][j] = dp[n][j - nums[i-1]]  + dp[i-1][j]; //  再看  这个n很神奇
            }
        }
    }
    return dp[n][target];
}

// 1维dp
int combinationSum41(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int& num : nums) {
            if (num <= i && dp[i - num] < INT_MAX - dp[i]) {  //同时需要防止溢出
                dp[i] += dp[i - num];
            }
        }
    }
    return dp[target];
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    int target = 4;
    int ans = combinationSum4(nums, target); // 7
    cout << ans;
    return 0;
}

