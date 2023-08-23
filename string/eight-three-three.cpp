// 833. 字符串中的查找与替换

// 模拟即可

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    int n = indices.size();
    vector<pair<int ,int>> isConver(n);
    for (int i = 0; i < n;i++)
    {
        int index = s.find(sources[i], indices[i]);
        if(index == indices[i]){
            isConver[i] = {index, i};
        }else{
            isConver[i] = {-1, -1};
        }
    }
    int len = s.length();
    // 排序
    sort(isConver.begin(), isConver.end());
    // 开始替换
    int dis = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> curr = isConver[i];
        if(curr.first == -1){
            continue;
        }

        int s_idx = curr.second;
        int len1 = sources[s_idx].length();
        int len2 = targets[s_idx].length();
        if(i==0 || isConver[i-1].first==-1){
            int startIdx = curr.first;
            // 删除灾添加；
            // 添加
            s.insert(startIdx, targets[s_idx]);
            s.erase(startIdx+len2, len1);
        }else{
             // 允许替换
            int prelen1 = sources[isConver[i-1].second].length();
            int prelen2 = targets[isConver[i-1].second].length();

            dis += (prelen2 - prelen1); // 需要每次根据删除和替换的长度来修改开始下标
            int startIdx = curr.first + dis;
            // 删除灾添加；
            // 添加
            s.insert(startIdx, targets[s_idx]);
            s.erase(startIdx+len2, len1);
        } 
    }
    return s;
}

int main(int argc, char const *argv[])
{
    string s = "wreorttvosuidhrxvmvo";
    vector<int> indxs = {14,12,10,5,0,18};
    vector<string> sources = {"rxv","dh","ui","ttv","wreor","vo"};
    vector<string> target = {"frs","c","ql","qpir","gwbeve","n"};
    string ans = findReplaceString(s, indxs, sources, target);
    cout << ans;
    return 0;
}
