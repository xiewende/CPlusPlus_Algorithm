// 560. 和为 K 的子数组
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

// 解题思路：前缀和 + HashMap

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace  std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> visit = {{0, 1}};
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if(visit.count(sum - k)){
            ans = ans + visit[sum - k];
            // visit[sum] = visit[sum] + 1;
        }
        // if(visit.count(sum)){
        //     visit[sum]++;
        // }else{
        //     visit[sum] = 1;
        // }
        visit[sum]++; //原来有某个key则加1，若初始没有则初始值0+1 =1
        }

    return ans;
}

int subarraySum1(vector<int>& nums, int k){
    if (nums.empty())
        return 0;
    unordered_map<int, int> m;
    // This line is important, or it will lost the first match.
    m[0] = 1; 
    
    int sum = 0;
    int res = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
        res += m[sum - k];
        m[sum]++;
    }
    return res;
}

int main(){
    vector<int> nums {1,-1,0};
    int k = 0;
    int ans = subarraySum(nums, k);
    cout<< ans << endl;
    return 0;
}

