// 剑指 Offer II 008. 和大于等于 target 的最短子数组

#include<iostream>
#include<vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int len = nums.size();
    int curr_sum = 0;
    int left = 0;
    int ans = len+1;
    for (int right = 0; right < len; right++)
    {
        curr_sum += nums[right];
        while(curr_sum >= target){
            curr_sum -= nums[left];
            ans = min(ans, right - left + 1);
            left++;
        }
    }
    return ans == len + 1 ? 0 : ans;
}

int main(int argc, char const *argv[])
{

    vector<int> nums = {1,1,1,1,1,1,1,1};
    int target = 11;
    int ans = minSubArrayLen(target, nums);
    cout << ans;
    return 0;
}
