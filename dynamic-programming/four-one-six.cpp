// 416. 分割等和子集

// 解题思路：动态规划，转换为0-1背包问题

// 理解为：给定一个只包含正整数的非空数组 nums，判断是否可以从数组中选出一些数字，使得这些数字的和等于整个数组的元素和的一半

// dp[i][j] 表示从数组的 [0,i]下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j。初始时，dp 中的全部元素都是 false

// 当 j>nums[i]:
//             如果不选取 nums[i]，则 dp[i][j] = dp[i-1][j]
//             如果选取 nums[i]，则 dp[i][j] = dp[i-1][j-nums[i]]
// 当 j<nums[i]:
//             在选取的数字的和等于j的情况下无法选取当前数字，则 dp[i][j] = dp[i-1][j]

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % 2 != 0){
        return false;
    }

    int half = sum / 2;

    vector<vector<int>> dp(n+1, vector<int>(half + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= half;j++)
        {
            if(j < nums[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[n][half];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 5, 11, 5};
    bool ans = canPartition(nums);
    cout << ans;
    return 0;
}
