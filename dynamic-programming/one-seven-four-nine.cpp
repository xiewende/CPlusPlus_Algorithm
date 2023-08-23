// 1749. 任意子数组和的绝对值的最大值

// 动态规划，子数组的最大值和最小值

// dpMax[i]:以i位置元素结尾的最大子数组和
// dpMin[i]:以i位置元素结尾的最小子数组和

// 状态转移方程：
// dpMax[i] = max(dpMax[i-1]+nums[i], nums[i])
// dpMin[i] = min(dpMin[i-1]+nums[i], nums[i])

// 返回，需要遍历 dpMax[i]和dpMin[i],取二者绝对值大者！

#include<iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
#include<vector>

using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> dpMax(n, 0);
    vector<int> dpMin(n, 0);
    dpMax[0] = nums[0];
    dpMin[0] = nums[0];
    int ans = abs(dpMax[0]);
    for (int i = 1; i < n; i++)
    {
        dpMax[i] = max(dpMax[i - 1] + nums[i], nums[i]);
        dpMin[i] = min(dpMin[i - 1] + nums[i], nums[i]);
        ans = max(ans, max(abs(dpMax[i]), abs(dpMin[i])));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,-5,1,-4,3,-2};
    int ans = maxAbsoluteSum(nums);
    cout << ans;
    return 0;
}
