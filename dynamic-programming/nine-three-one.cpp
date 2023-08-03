// 931. 下降路径最小和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // 初始化：第一行为初始值
    for (int j = 0; j < m;j++)
    {
        dp[0][j] = matrix[0][j];
    }
    // 只有一列
    if(m==1){
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            ans += matrix[i][0];
        }
        return ans;
    }
    // 从第二行开始遍历
    for (int i = 1; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            // 第一列不可以从左上角得到值
            if(j==0){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
            }else if(j==n-1){
                // 最后一列不可以从右上角得到值
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
            }else
            {
                // 中间列可以从正上方，左上方，右上方得到值
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + matrix[i][j];
            }
        }
    }

    // 返回dp最后一行的最大值
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
    int ans = minFallingPathSum(matrix);
    cout << ans;
    return 0;
}
