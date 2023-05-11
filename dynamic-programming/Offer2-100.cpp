// 剑指 Offer II 100. 三角形中最小路径之和

#include<iostream>
#include<vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    int col = triangle[row - 1].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < row;i++)
    {
        for (int j = 0; j < triangle[i].size();j++)
        {
            if(j==0){
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }else if(j==triangle[i].size()-1)
            {
                dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
            }else{
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < col;i++){
        ans = min(dp[row-1][i], ans);
    }
        return ans;
}

int minimumTotal1(vector<vector<int>>& triangle) {
    int row = triangle.size();
    int col = triangle[row - 1].size();
    // vector<vector<int>> dp(row, vector<int>(col, 0));
    vector<int> dp(col, 0);
    dp[0] = triangle[0][0];
    
    for (int i = 1; i < row;i++)
    {
        for (int j = triangle[i].size()-1; j >=0;j--)
        {
            if(j==0){
                dp[j] = dp[j] + triangle[i][j];
            }else if(j==triangle[i].size()-1)
            {
                dp[j] = dp[j-1] + triangle[i][j];
            }else{
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < col;i++){
        ans = min(dp[i], ans);
    }
        return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int ans = minimumTotal1(triangle);
    cout << ans;
    return 0;
}
