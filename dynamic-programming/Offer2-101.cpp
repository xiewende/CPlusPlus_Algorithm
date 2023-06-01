// 剑指 Offer II 101. 分割等和子集

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
#include<algorithm>

using namespace std;

bool canPartition(vector<int>& nums) {
    
    int len = nums.size();
    if(len<2){
        return false;
    }
    int sum = 0;
    int maxNum = 0;
    for (int i = 0; i < len;i++)
    {
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }
    if(sum%2!=0){
        return false;
    }

    int target = sum / 2;
    if(maxNum > target){
        return false;
    }

    vector<vector<bool>> dp(len, vector<bool>(target + 1, false));
    for (int i = 0; i < len;i++)
    {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;

    for (int i = 1; i < len;i++)
    {
        int num = nums[i];
        for (int j = 1; j <= target;j++)
        {
            if(j>=num){
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[len-1][target];
}

// 滚动数组实现空间优化
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
        return false;
    }
    int sum = 0, maxNum = 0;
    for (auto& num : nums) {
        sum += num;
        maxNum = max(maxNum, num);
    }
    if (sum & 1) {
        return false;
    }
    int target = sum / 2;
    if (maxNum > target) {
        return false;
    }
    vector<int> dp(target + 1, 0);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        for (int j = target; j >= num; --j) {
            dp[j] |= dp[j - num];
        }
    }
    return dp[target];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,8,9};
    bool ans = canPartition(nums);
    cout << ans;
    return 0;
}

