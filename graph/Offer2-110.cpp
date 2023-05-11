// 剑指 Offer II 110. 所有路径

// 解题思路

// 1、深度优先搜索，dfs
// 2、广度优先搜索，bfs

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


void dfs(vector<vector<int>> &ans, vector<int> &curr, vector<vector<int>>& graph, int node){
    if(node == graph.size()-1){
        ans.emplace_back(curr);
        return;
    }
    vector<int> curr_nodes = graph[node];
    for (int i = 0; i < curr_nodes.size();i++)
    {
        // 遍历到该节点放进去
        curr.emplace_back(curr_nodes[i]);
        dfs(ans, curr, graph, curr_nodes[i]);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    vector<int> curr;
    curr.emplace_back(0);
    dfs(ans, curr, graph, 0);
    return ans;
}

// bfs
struct point {
    int now;
    vector<int> path;
};
vector<vector<int>> allPathsSourceTarget1(vector<vector<int>>& graph) {
    int n = graph.size() - 1;
    vector<vector<int>> ans;
    queue<point> q;
    point p0;
    p0.now = 0; p0.path = {0};
    q.push(p0);
    while(!q.empty()) {
        auto tmp = q.front(); q.pop();
        for(auto nextp : graph[tmp.now]) {
            vector<int> tpath = tmp.path;
            tpath.push_back(nextp);
            if(nextp == n){
                ans.push_back(tpath);
            }else {
                point next;
                next.now = nextp;
                next.path = tpath;
                q.push(next);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> graph = {{1,2,3}, {2}, {3},{}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);
    for(auto currs:ans){
        for(auto curr:currs){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
