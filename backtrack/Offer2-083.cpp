// 剑指 Offer II 083. 没有重复元素集合的全排列

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<bool>& seen, int sum){
    if(sum == nums.size()){
        ans.push_back(curr);
    }
    for (int i = 0; i < nums.size();i++)
    {
        if(seen[i]){
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

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> seen(nums.size(), false);
    int sum = 0; // 元素个数
    dfs(ans, curr, nums, seen, sum);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for(auto currs:ans){
        for(auto curr:currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
