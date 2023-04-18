// 剑指 Offer II 079. 所有子集

#include<iostream>
#include<vector>

using namespace std;



void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int index){
    ans.push_back(curr);
    for (int i = index; i < nums.size(); i++)
    {
        curr.push_back(nums[i]);
        dfs(nums,ans, curr, i+1);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curr;
    vector<vector<int>> ans;
    dfs(nums, ans, curr, 0);
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans1 = subsets(nums);
    for(auto ves : ans1){
        for(auto curr : ves){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
