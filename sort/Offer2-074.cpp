// 剑指 Offer II 074. 合并区间

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    if(a[0]==b[0]){
        return a[1] < b[1];
    }else{
        return a[0] < b[0]; //第一个元素升序
    }
}   

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> ans;
    // int start = intervals[0][0];
    // int end = intervals[0][1];
    int idx = 0;
    while(idx < intervals.size()){
        int start = intervals[idx][0];
        int end = intervals[idx][1];
        // 说明有交集
        int next_idx = idx + 1;
        while(next_idx < intervals.size()  && intervals[next_idx][0] <= end){
            end = max(end, intervals[next_idx][1]);
            next_idx++;
        }
        // 添加答案
        // vector<int> curr = {start, end};
        ans.push_back({start,end});
        idx = next_idx;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> internals = {{1,4}, {4, 5}};
    vector<vector<int>> ans = merge(internals);
    for(auto currs:ans){
        for(auto curr:currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
