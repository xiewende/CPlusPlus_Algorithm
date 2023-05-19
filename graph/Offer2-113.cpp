// 剑指 Offer II 113. 课程顺序

// 解题思路：拓扑排序,需要记录节点的入度

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;
    
    edges.resize(numCourses);
    indeg.resize(numCourses);

    for (const auto& info: prerequisites) {
        edges[info[1]].push_back(info[0]);
        ++indeg[info[0]];
    }

    queue<int> q;
    // 将所有入度为 0 的节点放入队列中
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        // 从队首取出一个节点
        int u = q.front();
        q.pop();
        // 放入答案中
        result.push_back(u);
        for (int v: edges[u]) {
            --indeg[v];
            // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() != numCourses) {
        return {};
    }
    return result;
}
