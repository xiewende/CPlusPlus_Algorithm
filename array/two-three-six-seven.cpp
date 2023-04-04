// 2367. 算术三元组的数目

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// 暴力
int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0;
    int length = nums.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if(nums[j] - nums[i] == diff){
                for (int k = j + 1; k < length; k++)
                {
                    if(nums[k] - nums[j] == diff){
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

// 哈希求解
int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0;
    int length = nums.size();
    unordered_set<int> myset;
    for (int i = 0; i < length; i++)
    {
        myset.emplace(nums[i]);
    }
    for (int i = 0; i < length;i++)
    {
        if(myset.count(nums[i]+diff) && myset.count(nums[i]+2*diff)){
            ans++;
        }
    }
    return ans;
}
