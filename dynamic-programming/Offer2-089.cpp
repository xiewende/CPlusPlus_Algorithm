// 剑指 Offer II 089. 房屋偷盗
// 解题思路：动态规划

// dp[i]:代表小偷到第i家的时候的最大值，两个状态（偷i家；不偷i家）
// dp[i] = max(dp[i-2]+nums[i], dp[i-1]) 偷i家；不偷i家

// return dp[nums.length]

#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
    int length = nums.size();
    vector<int> dp(length + 1, 0 );
    dp[1] = nums[0];
    // dp[2] = nums[1];
    for (int i = 2; i <= length; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i - 1], dp[i-1]);
    }
    return dp[length];
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    int ans = rob(nums);
    cout << ans;
    return 0;
}