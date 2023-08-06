// 128. 最长连续序列

// 解题思路：set去重，并且存储每个值

// 开始遍历，只需要找到最小值x开始往上找x+1，x+2，x+3，,....,是否存在即可
// 遍历的时候，若x-1存在哈希表中，说明x不是最小值，直接跳过即可。

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet;
    for (int i = 0; i < nums.size(); i++)
    {
        numSet.emplace(nums[i]);
    }
    int ans = 0;
    for(auto curr : numSet){
        // 判断x-1是否存在，若存在，则x不是最小值，直接跳过即可
        if(numSet.count(curr-1)>0){
            continue;
        }
        // 开始遍历x+1，x+2，...是否存在，计算其长度
        int currLen = 1;
        while(numSet.count(curr+1)){
            curr = curr + 1;
            currLen += 1;
        }
        ans = max(ans, currLen);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int ans = longestConsecutive(nums);
    cout << ans;
    return 0;
}
