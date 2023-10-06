// 152. 乘积最大子数组

// 动态规划

#include<iostream>
#include<vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    // 需要判断正负，最大最小
    vector<int> dpMax(n, 0);
    vector<int> dpMin(n, 0);
    dpMax[0] = nums[0];
    dpMin[0] = nums[0];
    int ans = dpMax[0];
    for(int i=1;i<n;i++){
        dpMax[i] = max(max(dpMax[i - 1] * nums[i], dpMin[i -1 ] * nums[i]), nums[i]); // 前一个最大*当前，前一个最小*当前，当前，三者取最大
        dpMin[i] = min(min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i]), nums[i]); // 和上面类似
        ans = max(ans, dpMax[i]);
    }
    // cout << dpMax[n - 1];
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,0,-1};
    int ans = maxProduct(nums);
    cout << ans;
    return 0;
}
