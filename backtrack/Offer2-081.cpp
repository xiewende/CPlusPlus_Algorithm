// Offer II 081. 允许重复选择元素的组合

#include<iostream>
#include<vector>

using namespace std;


void dfs(vector<vector<int>> &ans, vector<int> &curr, vector<int>& candidates, int sum,int target, int index){
    if(sum == target){
        ans.push_back(curr);
        return;
    }

    for (int i = index; i < candidates.size();i++)
    {
        if(sum+candidates[i]>target){
            continue;
        }

        curr.push_back(candidates[i]);
        dfs(ans, curr, candidates, sum + candidates[i], target, i);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(ans, curr, candidates, 0, target, 0);
    return ans;
}

int main(){
    vector<int> candidates = {2};
    int target = 1;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for(auto currs : ans){
        for(auto curr : currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}