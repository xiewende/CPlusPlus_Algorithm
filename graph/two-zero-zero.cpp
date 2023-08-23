// 200. 岛屿数量

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

// bfs
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(grid[i][j] == '0' || seen[i][j]){
                continue;
            }
            q.push({i,j});
            ans++;
            seen[i][j] = true;
            while(!q.empty()){
                pair<int, int> position = q.front();
                q.pop();
                for (int i = 0; i < 4;i++)
                {
                    int next_i = position.first + dirs[i].first;
                    int next_j = position.second + dirs[i].second;
                    if(next_i>=0 && next_i<n && next_j>=0 && next_j<m && grid[next_i][next_j]=='1' && !seen[next_i][next_j]){
                        q.push({next_i, next_j});
                        seen[next_i][next_j] = true;
                    }
                }
            }
        }
    }
    return ans;
}

// dfs
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& seen, int x, int y){
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4;i++)
    {
        int next_i = x + dirs[i].first;
        int next_j = y + dirs[i].second;
        // 满足情况，进入递归
        if(next_i>=0 && next_i<n && next_j>=0 && next_j<m && grid[next_i][next_j]=='1' && !seen[next_i][next_j]){
            seen[next_i][next_j] = true;
            dfs(grid, seen, next_i, next_j);
        }
    }
}

int numIslands1(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(grid[i][j] == '0' || seen[i][j]){
                continue;
            }
            dfs(grid, seen, i,j);
            ans++;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    int ans = numIslands(grid);
    cout << ans;
    return 0;
}
