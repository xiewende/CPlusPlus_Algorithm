// 剑指 Offer II 080. 含有 k 个元素的组合

#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &ans, vector<int> &curr, int n, int k, int index){
    if(curr.size() == k){
        ans.push_back(curr);
        return;
    }
    for(int i = index; i <= n; i++){
        curr.push_back(i);
        dfs(ans, curr, n, k, i+1);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> combine(int n, int k) {
    vector<int> curr;
    vector<vector<int>> ans;
    dfs(ans ,curr, n, k, 1);
    return ans;
}

int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> ans = combine(n, k);
    for(auto currs : ans){
        for(auto curr : currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}