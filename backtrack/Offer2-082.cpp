// 剑指 Offer II 082. 含有重复元素集合的组合

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void dfs(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int idx, int target){
    if(target == 0){
        ans.emplace_back(curr);
        return;
    }

    for (int i = idx; i < candidates.size(); i++)
    {   
        // 剪枝
        if(target - candidates[i] < 0){
            break;
        }
        // 去重, 这是难点 i>idx 代表是是在这个轮次只能选择同样的数字是一次，但是下一轮次的第一个是允许选择和前面相同的数字的
        if(i > idx && candidates[i]==candidates[i-1]){
            continue;
        }

        //加入集合
        curr.emplace_back(candidates[i]);
        //调用递归
        dfs(candidates, ans, curr, i + 1, target - candidates[i]);
        // 恢复状态
        curr.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // 先排序，好去重
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(candidates, ans, curr, 0, target);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> candidates = {2,5,2,1,2};
    int target = 7;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for(auto currs : ans){
        for(auto curr : currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
