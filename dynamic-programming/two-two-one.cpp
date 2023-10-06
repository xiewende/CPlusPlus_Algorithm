// 221.最大正方形


#include<iostream>
#include<vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0)); // 每个格子作为正方形右下角的边长，最后返回一个平方即可
    int ans = 0; //最大正方形的边长
    for (int i = 0; i < n;i++)
    {
        if(matrix[i][0] == '1'){
            dp[i][0] = 1;
            ans = 1;
        }
    }
    for (int j = 0; j < m;j++)
    {
        if(matrix[0][j] == '1'){
            dp[0][j] = 1;
            ans = 1;
        }
    }

    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j < m;j++)
        {
            if(matrix[i][j] == '0'){
                dp[i][j] = 0;
            }else{
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans * ans; // 返回面积
}

int main(int argc, char const *argv[])
{
    // vector<vector<char>> matrix = {{"1","0","1","0",0}};
    return 0;
}

