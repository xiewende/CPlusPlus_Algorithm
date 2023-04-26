// 1027. 最长等差数列

// 解题思路：动态规划

// dp[i][d]: 表示在nums[i]结束的数组中以d为等差的最大长度

// 转移方程：

// int d = nums[i]-nums[j]  0<=j<i
// dp[i][d] = dp[j][d] + 1 

#include<iostream>
#include<vector>

using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> dp(len, vector<int>(1001, 1));
    int ans = 0;
    for (int i = 1; i < len;i++)
    {
        for (int j = 0; j < i; j++)
        {
            int d = nums[i] - nums[j] + 500;
            dp[i][d] = dp[j][d] + 1;
            ans = max(ans, dp[i][d]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {9,4,7,2,10};
    int ans = longestArithSeqLength(nums);
    cout << ans;
    return 0;
}