// 63. 不同路径 II

#include<iostream>
#include<vector>

using namespace std;

// 动态规划，只不过是多一个障碍物的判断，若某个格子是障碍物，则到达该点的路径为0，注意初始化
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // 初始化
    for (int i = 0; i < n;i++)
    {
        if(obstacleGrid[i][0]==1){
            break;
        }
        dp[i][0] = 1;
    }
    for (int j = 0; j < m;j++)
    {
        if(obstacleGrid[0][j]==1){
            break;
        }
        dp[0][j] = 1;
    }

    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j < m;j++)
        {
            // 当前位置为障碍物
            if(obstacleGrid[i][j]==1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[n-1][m-1];
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ans = uniquePathsWithObstacles(obstacleGrid);
    cout << ans;
    return 0;
}
