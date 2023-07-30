// 剑指 Offer II 105. 岛屿的最大面积

// 队列

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int ans = 0;
    queue<pair<int, int>> myqueue;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(grid[i][j] == 0 || visited[i][j]){
                continue;
            }

            int curr_ans = 0;
            myqueue.push({i, j});
            visited[i][j] = true;
            while(!myqueue.empty()){
                pair<int,int> curr = myqueue.front();
                myqueue.pop();
                curr_ans++;
                int curr_i = curr.first;
                int curr_j = curr.second;
                for (int k = 0; k < 4;k++)
                {
                    int next_i = curr_i + dirs[k].first;
                    int next_j = curr_j + dirs[k].second;
                    if(next_i<0 || next_i>=row || next_j<0 || next_j>=col || grid[next_i][next_j]==0 || visited[next_i][next_j]){
                        continue;
                    }
                    //加入队列
                    myqueue.push({next_i, next_j});
                    visited[next_i][next_j] = true;
                }
            }
            ans = max(ans, curr_ans);
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ans = maxAreaOfIsland(grid);
    cout << ans;
    return 0;
}