// 剑指 Offer II 116. 省份数量

// 解题思路，构建图+bfs即可

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

// bfs
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    // int col = isConnected[0].size();

    // 构造图的关系，key：城市节点，values：与之相连的城市节点
    unordered_map<int, vector<int>> grap;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(isConnected[i][j] == 1){
                grap[i].emplace_back(j);
                grap[j].emplace_back(i);
            }
        }
    }

    // 判断是否访问过
    vector<bool> visited(n, false);
    // 实现广度优先遍历的队列
    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {   
        // 访问过的节点，跳过
        if(visited[i]){
            continue;
        }
        // 没有访问过的节点
        count++;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            // 遍历当前城市节点所有相连的城市节点
            for(auto tem : grap[curr]){
                if(visited[tem]){
                    continue;
                }
                // 入队
                q.push(tem);
                visited[tem] = true;
            }
        }
    }

    return count;
}


// dfs
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities, int i) {
    for (int j = 0; j < cities; j++) {
        if (isConnected[i][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, visited, cities, j);
        }
    }
}

int findCircleNum1(vector<vector<int>>& isConnected) {
    int cities = isConnected.size();
    vector<int> visited(cities);
    int provinces = 0;
    for (int i = 0; i < cities; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, cities, i);
            provinces++;
        }
    }
    return provinces;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    int ans = findCircleNum(isConnected);
    cout << ans;
    return 0;
}

