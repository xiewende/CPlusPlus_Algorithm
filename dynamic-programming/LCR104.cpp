// LCR 104. 组合总和 Ⅳ

// 解题思路：完全背包问题

#include <iostream>
#include <vector>

using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1);
    dp[0] = 1;
    for (int j = 1; j <= target;j++)
    {
        for (int i = 0; i < n;i++)
        {
            if(j>=nums[i]){
                dp[j] += dp[j-nums[i]];
            }
        }
    }
    return dp[target];
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    int target = 4;
    int ans = combinationSum4(nums, target);
    cout << ans;
    return 0;
}
