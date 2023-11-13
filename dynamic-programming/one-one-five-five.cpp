// 1155. 掷骰子等于目标和的方法数

// 动态规划 类似背包问题

// dp[i][j] : 第 i 个骰子，和为 j 的方案数

// 遇到第 i 个骰子的时候，dp[i][j] = sum（dp[i-1][j-kk]）, 其中 kk 就是骰子可能得到的结果【1，k】，多了一个内循环遍历

// 返回 dp[n][target]

#include<iostream>
#include<vector>

using namespace std;

int numRollsToTarget(int n, int k, int target) {
    if(n*k < target){
        return -1;
    }

    int mod = 1e9 + 7;

    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    dp[0][0] = 1;
    // 初始化
    for(int i = 1; i<=n; i++){
        for(int j=1;j<=target;j++){
            dp[i][j] = 0;
            for(int kk=1;kk<=k;kk++){
                if(j>=kk){
                    dp[i][j] += (dp[i-1][j-kk] % mod);
                }
            }
        }
    }

    return dp[n][target];
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 30;
    int k = 30;
    int target = 500;
    int ans = numRollsToTarget(n, k, target);
    cout << ans;
    return 0;
}
