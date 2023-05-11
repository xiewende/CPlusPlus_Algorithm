// 剑指 Offer II 099. 最小路径之和

#include<iostream>
#include<vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 101));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if(i==1 && j==1){
                continue;
            }else if(i==1)
            {
                dp[i][j] = dp[i][j-1] + grid[i - 1][j - 1];
            }else if(j==1)
            {
                dp[i][j] = dp[i-1][j] + grid[i - 1][j - 1];
            }else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
    }
    return dp[row][col];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grids = {{1,3,1}, {1,5,1},{4,2,1}};
    int ans = minPathSum(grids);
    cout << ans;
    return 0;
}
