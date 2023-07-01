// 面试题 16.19. 水域大小

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

vector<int> pondSizes(vector<vector<int>>& land) {
    int row = land.size();
    int col = land[0].size();
    // 记录某个点是否被访问过
    vector<vector<bool>> seen(row, vector<bool>(col, false));
    // 记录八个方向
    vector<pair<int, int>> dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    // bfs需要的队列问题
    queue<pair<int, int>> q;
    // 答案返回
    vector<int> ans;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // 若某个点的值不为0 或者 该点为0但是已经访问过了，则跳过
            if(land[i][j]!=0 || seen[i][j]){
                continue;
            }
            // 该点为0且没有访问过
            int curr_ans = 0;
            q.push({i,j});
            seen[i][j] = true;
            while(!q.empty()){
                // 取值和退出队列
                pair<int, int> curr = q.front();
                q.pop();
                curr_ans++;
                // 判断八个方向
                for (int k = 0; k < 8;k++)
                {
                    int next_i = curr.first + dirs[k].first;
                    int next_j = curr.second + dirs[k].second;
                    //满足是个水域
                    if(next_i>=0 && next_i<row && next_j>=0 && next_j<col && land[next_i][next_j]==0 && !seen[next_i][next_j]){
                        q.push({next_i,next_j});
                        seen[next_i][next_j] = true;
                    }
                }
            }
            // 添加到答案
            ans.emplace_back(curr_ans);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> land = {{0,2,1,0},{0,1,0,1},{1,1,0,1},{0,1,0,1}};
    vector<int> ans = pondSizes(land);
    for(auto tem:ans){
        cout << tem << " ";
    }
    return 0;
}
