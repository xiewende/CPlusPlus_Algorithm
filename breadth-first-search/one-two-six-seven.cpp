// 1267. 统计参与通信的服务器

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

// bfs
int countServers(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(grid[i][j] == 0 || visited[i][j]==true){
                continue;
            }
            q.push({i, j});
            visited[i][j] = true;
            int currA = 0;
            while(!q.empty()){
                pair<int, int> curr = q.front();
                q.pop();
                int ci = curr.first;
                int cj = curr.second;
                // 横着找
                for (int jj = 0; jj < m; jj++)
                {
                    if(grid[ci][jj] == 0 || visited[ci][jj]==true || jj==cj){
                        continue;
                    }
                    q.push({ci, jj});
                    visited[ci][jj] = true;
                    currA++;

                }
                // 竖着找
                for (int ii = 0; ii < n; ii++)
                {
                    if(grid[ii][cj] == 0 || visited[ii][cj]==true || ii==ci){
                        continue;
                    }
                    q.push({ii, cj});
                    visited[ii][cj] = true;
                    currA++;
                }
            }
            //
            currA = currA == 0 ? 0 : currA + 1;
            ans += currA;
        }
    }
    return ans;
}

// dfs
int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
    int ans = 1;
    // 横着
    for (int j = 0; j < grid[0].size(); j++)
    {
        if(grid[row][j] == 0 || visited[row][j] || j==col){
            continue;
        }
        visited[row][j] = true;
        ans += dfs(grid, row, j, visited);
    }
    // 竖着
    for (int i = 0; i < grid.size(); i++)
    {
        if(grid[i][col] == 0 || visited[i][col] || i==row){
            continue;
        }
        visited[i][col] = true;
        ans += dfs(grid, i, col, visited);
    }
    return ans;
}
// dfs
int countServers1(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(grid[i][j] == 0 || visited[i][j]==true){
                continue;
            }
            visited[i][j] = true;
            int curr = dfs(grid, i, j, visited);
            ans += curr == 1 ? 0 : curr;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    // vector<vector<int>> grid = {{1,0}, {1,1}};
    int ans = countServers1(grid);
    cout << ans;
    return 0;
}
