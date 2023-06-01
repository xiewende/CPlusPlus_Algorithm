// 剑指 Offer II 009. 乘积小于 K 的子数组

#include<iostream>
#include<vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int len = nums.size();
    int left = 0;
    int right = 0;
    int ans;
    int chengji = 1;
    while (right < len)
    {
        //计算乘积
        chengji = chengji * nums[right];
        while(left <= right && chengji >= k){
            chengji = chengji / nums[left];
            left++;
        }
        // 答案每次新加的是以 nums[right]结尾满足题意的子数组个数
        // right - left + 1 新加一个元素满足条件，则答案相加的是以新加元素为结尾的满足题意得子数组；
        ans += right - left + 1;
        right++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    int ans = numSubarrayProductLessThanK(nums, k);
    cout << ans;
    return 0;
}
