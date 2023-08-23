// 1388. 3n 块披萨

// 问题转化，3n长环形数组中，全部不相邻任意n个数的最大值

// 环形数组，类似打家劫舍，将环形数组分为【1,n】和【0，n-1】，分别计算这两个子数组取其大就可以

// 定义：dp[i][j], 在数组i之前选择j个数的最大值
//     1、选取当前元素 nums[i]，则 dp[i][j] = dp[i - 2][j - 1] + nums[i];
//     2、未选取当前元素，则 dp[i][j] = dp[i-1][j]
//     3、上述两者返回最大即可

// 初始化
// dp[0][0] = 0;
// dp[0][1] = nums[0];
// dp[1][0] = 0;
// dp[1][1] = max(nums[0], nums[1])


#include<iostream>
#include<vector>

using namespace std;

int maxSizeOne(vector<int>& nums) {
    int n = nums.size();
    int k = (n+1) / 3;
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    dp[1][0] = 0;
    dp[1][1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= k;j++)
        {
            dp[i][j] = max(dp[i - 2][j - 1] + nums[i], dp[i - 1][j]);
        }
    }
    return dp[n - 1][k];
}

int maxSizeSlices(vector<int>& slices) {
    vector<int> nums1(slices.begin(), slices.end()-1);
    vector<int> nums2(slices.begin() + 1, slices.end());
    int ans1 = maxSizeOne(nums1);
    int ans2 = maxSizeOne(nums2);
    return max(ans1, ans2);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int ans = maxSizeSlices(nums);
    cout << ans;
    return 0;
}
