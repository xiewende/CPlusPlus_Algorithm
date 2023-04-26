// 2418. 按身高排序

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    unordered_map<int, string> stored;
    int len = names.size();
    for (int i = 0; i < len;i++)
    {
        stored[heights[i]] = names[i];
    }
    sort(heights.begin(), heights.end());

    vector<string> ans;

    for (int i = len - 1; i >= 0;i--)
    {
        ans.push_back(stored[nums[i]]);
    }
    return ans;
}