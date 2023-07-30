// 剑指 Offer II 084. 有重复元素集合的全排列

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<bool>& seen, int sum){
    if(sum == nums.size()){
        ans.push_back(curr);
    }
    for (int i = 0; i < nums.size();i++)
    {
        // 去重为重点
         if (seen[i] || (i > 0 && nums[i] == nums[i - 1] && seen[i - 1]==0)) {
                continue;
            }
        // 加入答案
        curr.push_back(nums[i]);
        seen[i] = true;
        dfs(ans, curr, nums, seen, sum + 1);
        // 状态恢复
        curr.pop_back();
        seen[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> seen(nums.size(), false);
    int sum = 0; // 元素个数
    sort(nums.begin(), nums.end()); //一定需要先排序
    dfs(ans, curr, nums, seen, sum);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,3,0,3};
    vector<vector<int>> ans = permuteUnique(nums);
    for(auto currs:ans){
        for(auto curr:currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
