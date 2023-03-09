
// 剑指 Offer 47礼物的最大价值价值
// 解题思路：遇到题目说最大值或者最小值的最值问题，可以第一时间想到是动态规划问题，动态规划问题很适合解决最值问题
// 定义 dp[i][j] 为在位置（i，j）时所获得最大价值，根据题目要求，返回值时dp[n][n];
// 状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];  grid[i][j]为网格值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxValue(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for (int i = 1; i < row + 1;i++)
    {
        for (int j = 1; j <= col; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[row][col];
}


int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    for(auto ves: grid){
        for(auto item: ves){
            cout << item ;
        }
        cout << endl;
    }
    int ans = maxValue(grid);
    cout << "ans is " << ans << endl;
}