// 1911. 最大子序列交替和

// 解题思路：动态规划，

// 单个dp，双重循环，超时
// 定义：
// dp[i]：以i为结尾的最大交替和
// 状态转移方程：
// 遍历i；
//     同时遍历 0<j<i；以j位置作为i的前一个交替的和，此时同时记录在区间【j，i】中的最小值，
//     dp[i] = max(dp[j]+nums[i] - 最小值)；
// 返回：
// 遍历dp[i] 返回最大值即可 


// 两个dp：也就是状态DP，单重循环

// dp0[i]: 在 i 之前选中一个一个子序列（未必包含nums[i]）并且选中的子序列中最后一个元素下标为偶数
// dp1[i]: 在 i 之前选中一个一个子序列（未必包含nums[i]）并且选中的子序列中最后一个元素下标为奇数

// 状态转移方程
// 对于dp0[i]
//     若 nums[i] 被选择，dp0[i] = dp1[i-1] + nums[i]
//     否则：dp0[i] = dp0[i-1]
// 对于dp1[i]
//     若 nums[i]被选择，dp1[i] = dp0[i-1] - nums[i]
//     否则：dp1[i] = dp1[i-1]


#include<iostream>
#include<vector>

using namespace std;

// 单个dp，双重循环，超时
long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<long long> dp(n, 0);
    dp[0] = nums[0];
    long long ans = dp[0];
    for (int i = 1; i < n;i++)
    {
        // 【j，i】区间的最小值
        int curr_min = nums[i - 1];
        // 以 i 结尾的，往前遍历得到的左右交替和的最大值 
        long long curr_max = nums[i];
        for (int j = i - 2; j >= 0;j--)
        {
            curr_max = max(curr_max, nums[i] + dp[j] - curr_min);
            curr_min = min(curr_min, nums[j]);
        }
        dp[i] = curr_max;
        ans = max(ans, dp[i]);
    }
    return ans;
}

// 两个dp：也就是状态DP，单重循环
long long maxAlternatingSum1(vector<int>& nums) {
    int n = nums.size();
    vector<long long> dp0(n, 0);  // 偶数目
    vector<long long> dp1(n, 0); // 奇数
    dp0[0] = nums[0];
    dp1[0] = 0;
    // long long ans = dp[0];
    for (int i = 1; i < n;i++)
    {
        dp0[i] = max(dp0[i-1], dp1[i-1] + nums[i]);
        dp1[i] = max(dp1[i-1], dp0[i-1] - nums[i]);
    }
    return dp0[n-1];
}

// 两个dp：也就是状态DP，单重循环, dp[i]只与dp[i-1]有关，可以利用滚动数字压缩空间
long long maxAlternatingSum2(vector<int>& nums) {
    int n = nums.size();
    // vector<long long> dp0(n, 0);  // 偶数目
    // vector<long long> dp1(n, 0); // 奇数
    long long dp0= nums[0];
    long long dp1 = 0;
    // long long ans = dp[0];
    for (int i = 1; i < n;i++)
    {
        dp0 = max(dp0, dp1 + nums[i]);
        dp1 = max(dp1, dp0 - nums[i]);
    }
    return dp0;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,2,5,3};
    long long ans = maxAlternatingSum(nums);
    cout << ans;
    return 0;
}



