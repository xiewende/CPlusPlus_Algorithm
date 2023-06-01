// 剑指 Offer II 102. 加减的目标值

// 解题思路：转化+动态规划 0-1背包问题

// 1、转化
// 记 nums数组的和为 sum，则全部添加 + 号
// 若在这里满足题意中，nums数组中添加 - 号的数字之和是negSum，则添加＋号的和就是 sum-negSum，此时满足题意得表达式的值就是 sum-negSum-negSum = target
// 则 negSum = （sum-target）/ 2,
// 由于数组 nums 中的元素都是非负整数，negSum 也必须是非负整数，所以上式成立的前提是 sum−target 是非负偶数。若不符合该条件可直接返回0。
// 若上式成立，问题转化成在数组 nums 中选取若干元素，使得这些元素之和等于 negSum，计算选取元素的方案数。我们可以使用动态规划的方法求解。类似0-1背包问题

// 动态规划

// dp[i][j] : 表示在数组 nums 的前i个数中选取元素，使得这些元素之和等于 j 的方案数，返回 dp[n][negSum],

// 初始化：
//         dp[0][0] = 1,
//         dp[0][j] = 0;
// 当 1 < i < n;
// 遍历 0 <= j <= negSum
//                    若 j<nums[i] : 则不能选nums[i], 此时 dp[i][j] = dp[i - 1][j] 若 j>
//                        nums[i] : 可以不选nums[i], dp[i][j] = dp[i - 1][j];
//                                  可以选择nums[i], dp[i][j] = dp[i-1][j-nums[i]]
//                                  所以 dp[i][j] = dp[i - 1][j] + dp[i-1][j-nums[i]]

#include<iostream>
#include<vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int& num : nums) {
        sum += num;
    }
    // int sum = accumulate(nums.begin(), nums.end(), 0); 库函数求和
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
        return 0;
    }
    int n = nums.size(), negSum = diff / 2;
    //建立 dp 数组
    vector<vector<int>> dp(n + 1, vector<int>(negSum + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int num = nums[i - 1];
        for (int j = 0; j <= negSum; j++) {
            // dp[i][j] = dp[i - 1][j];
            // if (j >= num) {
            //     dp[i][j] += dp[i - 1][j - num];
            // }
            if(j<num){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
            }
        }
    }
    return dp[n][negSum];
}

// 空间优化，滚动数组
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int& num : nums) {
        sum += num;
    }
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
        return 0;
    }
    int neg = diff / 2;
    vector<int> dp(neg + 1);
    dp[0] = 1;
    for (int& num : nums) {
        for (int j = neg; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    return dp[neg];
}
