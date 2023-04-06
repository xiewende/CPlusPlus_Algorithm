// 剑指 Offer 56 - I. 数组中数字出现的次数

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> visitd;
    for (int i = 0; i < nums.size(); i++)
    {   
        visitd[nums[i]]++;
        if(visitd[nums[i]] > 2){
            visitd.erase(nums[i]);
        }
    }
    return visitd.begin()->first;
}

int main(){
    vector<int> nums{3,4,3,3};
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
}