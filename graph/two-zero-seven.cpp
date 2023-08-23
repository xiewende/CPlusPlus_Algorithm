// 207. 课程表

// 拓扑排序

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
    // 图
    vector<vector<int>> graph(n);
    // 每个节点的入度
    vector<int> inputNode(n, 0);

    for (int i = 0; i < prerequisites.size();i++){
        graph[prerequisites[i][0]].emplace_back(prerequisites[i][1]); //构建图
        inputNode[prerequisites[i][1]]++; // 每个节点的入度
    }

    queue<int> q;
    for (int i = 0; i < n;i++)
    {
        // 入读为0的节点可以入队
        if(inputNode[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int next = q.front();
        q.pop();
        numCourses--; // 记录答案
        // 当前节点指向的节点们
        for(auto curr : graph[next]){
            // 指向的节点入读减一
            inputNode[curr]--;
            // 若该节点的入度为0，则可以入队
            if(inputNode[curr] == 0){
                q.push(curr);
            }
        }
    }

    return numCourses == 0; //判断即可
}

int main(int argc, char const *argv[])
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0,1}};
    bool ans = canFinish(numCourses, prerequisites);
    cout << ans;
    return 0;
}
