// 剑指 Offer 56 - II. 数组中数字出现的次数

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
    unordered_set<int> visitd;
    for (int i = 0; i < nums.size(); i++)
    {
        if(visitd.count(nums[i])){
            visitd.erase(nums[i]);
        }else{
            visitd.emplace(nums[i]);
        }
    }
    return vector<int>(visitd.begin(), visitd.end());
}

int main(){
    vector<int> nums{4,1,4,6};
    vector<int> ans = singleNumbers(nums);
    for(int curr : ans){
        cout << curr << " ";
    }
    return 0;
}