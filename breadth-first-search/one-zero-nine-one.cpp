// 1091. 二进制矩阵中的最短路径

// 解题思路：广度优先遍历

#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<queue>

using namespace std;


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]!=0){
        return -1;
    }
    // 八个方向的坐标表示
    vector<pair<int, int>> dirs = {{0,-1}, {-1,-1}, {-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0,0});
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        count++;
        for (int i = 0; i < size;i++)
        {
            auto curr = q.front();
            q.pop();
            // 若当前坐标为目标坐标
            if(curr.first==row-1 && curr.second==col-1){
                return count;
            }
            // 寻找下一个坐标满足的加入队列
            for (int k = 0; k < 8;k++)
            {
                int next_i = curr.first + dirs[k].first;
                int next_j = curr.second + dirs[k].second;
                // 满足
                if(next_i>=0 && next_i<row && next_j>=0 && next_j<col && !visited[next_i][next_j] && grid[next_i][next_j]==0){
                    q.push({next_i, next_j});
                    visited[next_i][next_j] = true;
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{1, 0,0}, {1,1, 0},{1,1,0}};
    int ans = shortestPathBinaryMatrix(grid);
    cout << ans;
    return 0;
}
