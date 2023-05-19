// 1335. 工作计划的最低难度

// 解题思路：动态规划 类似 1105 填充书架，从后往前看

// dp[i][j]: 表示 i 天完成 前 j 个工作的最小难度

// dp[i][j] = min (dp[i-1][k], maxzhi) 其中 k=i-1,...j-1   maxzhi = jobDifficulty[k].jobDifficulty[k+1]..jobDifficulty[j] 的最大值

// 倒叙从j到i-1遍历得到k

#include<iostream>
#include<vector>

using namespace std;


int minDifficulty(vector<int>& jobDifficulty, int d) {
    int len = jobDifficulty.size();
    if(len<d){
        return -1;
    }
    vector<vector<int>> dp(d+1, vector<int>(len, 0x3f3f3f3f));

    for (int i = 1; i <= d; i++)
    {
        int curr_max = 0;
        for (int j = 0; j < len; j++)
        {
            if(j+1 < i){
                continue;
            }
            curr_max = max(curr_max, jobDifficulty[j]);
            if(i==1){
                dp[i][j] = curr_max;
            }else{
                int curr_max_right = jobDifficulty[j];
                for (int k = j; k >= i-1; k--)
                {
                    curr_max_right = max(curr_max_right, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], curr_max_right + dp[i-1][k-1]);
                }
            }
        }
    }
    return dp[d][len - 1];
}

int main(int argc, char const *argv[])
{
    vector<int> jobDifficulty = {11,111,22,222,33,333,44,444};
    int d = 6;
    int ans = minDifficulty(jobDifficulty, d);
    cout << ans;
    return 0;
}

