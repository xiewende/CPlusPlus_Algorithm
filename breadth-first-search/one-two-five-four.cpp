// 1254. 统计封闭岛屿的数目

// 解题思路：bfs

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int closedIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();

    // 记录是否被访问过
    vector<vector<bool>> seen(row, vector<bool>(col, 0));
    // 四个方向
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // 队列
    queue<pair<int, int>> q;

    int ans = 0;
    for (int i = 1; i < row - 1;i++)
    {
        for (int j = 1; j < col - 1;j++)
        {   
            // 若不为0 或者 已经访问过则跳过
            if(grid[i][j] != 0 || seen[i][j]){
                continue;
            }

            // 入队
            q.push({i, j});
            seen[i][j] = true;
            bool tag = false;
            while(!q.empty()){
                pair<int, int> curr = q.front();
                q.pop();
                for (int k = 0; k < 4;k++)
                {
                    int next_i = curr.first + dirs[k].first;
                    int next_j = curr.second + dirs[k].second;
                    //满足是个水域
                    if(next_i>=0 && next_i<row && next_j>=0 && next_j<col && grid[next_i][next_j]==0 && !seen[next_i][next_j]){
                        q.push({next_i,next_j});
                        seen[next_i][next_j] = true;
                        if (next_i == 0 || next_i == row - 1 || next_j == 0 || next_j==col-1)
                        {
                            tag = true;
                        }
                    }
                }
            }

            if(!tag){
                ans += 1;
            }

        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    int ans = closedIsland(grid);
    cout << ans;
    return 0;
}
