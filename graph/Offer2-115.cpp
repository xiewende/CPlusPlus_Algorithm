// 剑指 Offer II 115. 重建序列

// // 解题思路：拓扑排序,需要记录节点的入度
// 按照 sequences[i] 数字出现的先后构建有向图，sequences[i][j] -》 sequences[i][j+1] 其中 前：箭头前节点；后：箭头后节点；

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
    // key:节点，value：该节点的指向的值
    int len = nums.size();
    unordered_map<int, vector<int>> grap;
    // 记录每个点的入度
    vector<int> inedge(len + 1, 0);
    // inedge.resize();

    for (int i = 0; i < sequences.size();i++)
    {
        for (int j = 0; j < sequences[i].size()-1;j++)
        {
            grap[sequences[i][j]].emplace_back(sequences[i][j+1]); //构件图
            inedge[sequences[i][j+1]]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= len;i++)
    {
        if(inedge[i]==0){
            q.push(i);
        }
    }

    // 判断为1，若入度不为1的为多个，肯定就是有多种答案
    // if(q.size() != 1){
    //     return false;
    // }

    int idx = 0;
    while (!q.empty()) {
        // 判断为1，若入度不为1的为多个，肯定就是有多种答案
        if(q.size()!=1){
            return false;
        }
        // 从队首取出一个节点
        int u = q.front();
        q.pop();
        // p判断和nums是否相等，不等就可以直接返回
        if(nums[idx]!=u){
            return false;
        }
        idx++;
        for (int v: grap[u]) {
            --inedge[v];
            // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
            if (inedge[v] == 0) {
                q.push(v);
            }
        }
    }
    return idx==len;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {4,1,5,2,6,3};
    vector<vector<int>> sequences = {{5,2,6,3},{4,1,5,2}};
    bool ans = sequenceReconstruction(nums, sequences);
    cout << ans;
    return 0;
}

