// 剑指 Offer II 107. 矩阵中的距离

#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row, vector<int>(col, row*col));

    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col;j++)
        {   
            if(mat[i][j] == 0){
                dp[i][j] = 0;
                continue;
            }
            if(i==0 && j==0){
                continue;
            }
            if(i==0 && j>0){
                dp[i][j] = dp[i][j - 1] + 1;
            }else if(j==0 && i>0){
                dp[i][j] = dp[i-1][j] + 1;
            }else{
                if(mat[i-1][j] == 0 || mat[i][j-1] == 0){
                    dp[i][j] = 1;
                }else
                {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
                }  
            }
        }
    }

    for (int i = row-1; i >= 0;i--)
    {
        for (int j = col-1; j >= 0;j--)
        {
            if(mat[i][j] == 0){
                dp[i][j] = 0;
                continue;
            }
            if(i==row-1 && j==col-1){
                continue;
            }
            if(i==row-1 && j<col-1){
                dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
            }else if(j==col-1 && i<row-1){
                dp[i][j] = min(dp[i][j],dp[i+1][j] + 1);
            }else{
                if(mat[i+1][j] == 0 || mat[i][j+1] == 0){
                    dp[i][j] = 1;
                }else
                {
                    dp[i][j] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j]) + 1);
                }  
            }
            
        }
    }

    return dp;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> ans = updateMatrix(mat);
    for(auto currs : ans){
        for(auto tem:currs){
            cout << tem << " ";
        }
        cout << endl;
    }
    return 0;
}


