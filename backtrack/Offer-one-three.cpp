//面试题13. 机器人的运动范围

// 解题思路 
// 搜索方向可以缩减为向右和向下

// 1、经典回溯
// 2、改为迭代
// vis[i][j] 为 (i, j) 坐标是否可达，如果可达返回 1，否则返回 0
// 首先 (i, j) 本身需要可以进入，因此需要先判断 i 和 j 的数位之和是否大于 k ，如果大于的话直接设置 vis[i][j] 为不可达即可。
// 搜索方向只需朝下或朝右，因此 (i, j) 的格子只会从 (i - 1, j) 或者 (i, j - 1) 两个格子走过来（不考虑边界条件），
// 那么 vis[i][j] 是否可达的状态则可由如下公式计算得到：
// vis[i][j]=vis[i−1][j] or vis[i][j−1]

#include<iostream>
#include<vector>
#include<utility>

using namespace std;


bool check(int i, int j, int k){
    int sum = 0;
    while(i != 0){
        sum += i % 10;
        i = i / 10;
    }
    while(j != 0){
        sum += j % 10;
        j = j / 10;
    }
    return sum<=k;
}

void dfs(int m, int n, int row, int col, int k, vector<pair<int, int>> dirs, vector<vector<bool>>& visited, int& ans){
    
    ans = ans + 1;
    visited[row][col] = true;
    for (int i = 0; i < dirs.size(); i++)
    {
        int next_row = row + dirs[i].first;
        int next_col = col + dirs[i].second;
        //剪枝
        if(next_row<0 || next_row>=m || next_col<0 || next_col>=n || !check(next_row, next_col, k) || visited[next_row][next_col]){
            continue;
        }
        //访问
        dfs(m, n, next_row, next_col, k, dirs, visited, ans);
    }
    return;
}

int movingCount(int m, int n, int k) {
    vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[0][0] = true;
    int ans = 0;
    dfs(m, n, 0, 0, k, dirs, visited, ans);
    return ans;
}

// 迭代
int movingCount1(int m, int n, int k) {
    if (!k) return 1;
    vector<vector<int> > vis(m, vector<int>(n, 0));
    int ans = 1;
    vis[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 && j == 0) || !check(i,j,k)) continue;
            // 边界判断
            if (i - 1 >= 0) vis[i][j] |= vis[i - 1][j];
            if (j - 1 >= 0) vis[i][j] |= vis[i][j - 1];
            ans += vis[i][j];
        }
    }
    return ans;
}


int main(){
    int m = 3;
    int n = 1;
    int k = 0;
    int ans = movingCount1(m, n, k);
    cout << ans;
    return 0;
}