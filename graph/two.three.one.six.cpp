// 2316. 统计无向图中无法互相到达点对数

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// bfs
int bfs(vector<vector<int>>& graphs, vector<bool>& visited, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int ans = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans++;
        for(auto next : graphs[curr]){
            if(visited[next]){
                continue;
            }
            visited[next] = true;
            q.push(next);
        }
    }

    return ans;
}

// dfs
int dfs(vector<vector<int>>& graphs, vector<bool>& visited, int node){
    visited[node] = true;
    int ans = 1;
    for(auto next : graphs[node]){
        if(visited[next]){
            continue;
        }
        ans += dfs(graphs, visited, next);
    }
    return ans;
}


long long countPairs(int n, vector<vector<int>>& edges) {

    // 构建图
    vector<vector<int>> graphs(n);
    for (int i = 0; i < edges.size();i++)
    {
        graphs[edges[i][0]].emplace_back(edges[i][1]);
        graphs[edges[i][1]].emplace_back(edges[i][0]);
    }

    // 是否遍历过
    vector<bool> visited(n, false);

    // 记录每个连通区域的节点个数
    // vector<int> nums;

    //  统计 
    long long ans = 0;
    long long sum = 0;

    for (int i = 0; i < n;i++)
    {
        // 已经遍历了，直接跳过
        if(visited[i]){
            continue;
        }
        // 否则开始
        int curr = dfs(graphs, visited, i);
        // nums.push_back(curr);
        ans += curr * sum;
        sum += curr;
    }

    // 统计
    // long long ans = 0;
    // long long sum = nums[0];
    // for (int i = 1; i < nums.size();i++)
    // {
    //     // for (int j = i + 1; j < nums.size(); j++)
    //     // {
    //     //     ans += (nums[i] * nums[j]);
    //     // }
    //     ans += (nums[i] * sum);
    //     sum += nums[i];
    // }

    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 7;
    vector<vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};

    int ans = countPairs(n, edges);
    cout << ans;
    return 0;
}

