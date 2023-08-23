//918. 环形子数组的最大和

// 解题思路：动态规划

// 取反的思想
// 如果子数组没有跨越边界，只有中间一段，就是普通的最大子数组和。
// 如果子数组 a 跨越边界，考虑不在子数组中的数，它们组成了一个中间的子数组 b。
// 那么有 sum(a)+sum(b)=sum(nums)=常数。所以 b 的元素和越小，a 的元素和就越大，所以相当于求最小子数组和。
// 用整个数组的元素和，减去最小子数组和，就得到了跨越边界的最大子数组和了。

// 求最小子数组和，有一个极端情况，就是最小子数组和 等于 数组总和
// 此时，应该直接返回最大子数组和答案
// 例如：全是负数的情况下

// 定义：
//     dp[i]：以元素nums[i] 结尾的最大子数组和

// 转移方程：
//     dp[i] = max(dp[i - 1] + nums[i], nums[i]);

// 记住：求数组的最大子数组和需要遍历 dp[i] 取最大！

#include<iostream>
#include<vector>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp_max(n, 0);
    vector<int> dp_min(n, 0);
    // 初始化
    dp_max[0] = nums[0];
    dp_min[0] = nums[0];
    // 数组和
    int sum = nums[0];
    int maxSum = nums[0];
    int minSum = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp_max[i] = max(dp_max[i-1]+nums[i], nums[i]);
        maxSum = max(maxSum, dp_max[i]);

        dp_min[i] = min(dp_min[i-1]+nums[i], nums[i]);
        minSum = min(minSum, dp_min[i]);

        sum += nums[i];
    }
    return minSum == sum ? maxSum : max(maxSum, sum - minSum);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,-3,5};
    int ans = maxSubarraySumCircular(nums);
    cout << ans;
    return 0;
}
