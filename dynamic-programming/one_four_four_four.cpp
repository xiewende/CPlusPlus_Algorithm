// 1444. 切披萨的方案数

//  动态规划：

// dp[c][i][j]:表示左上角（i，j），右下角（n-1， m-1）的子矩阵切c刀，每块都包含至少一个苹果的方案数

// 当c==0，也就是不切，dp[c][i][j], 若此区间有苹果则为1，没有则为0；左上角（i，j），右下角（n-1， m-1）
// 当c>0时，
//     垂直切：枚举j2（j<j2<m）,切出来的宽度就是j2-j，剩下的子矩形左上角（i，j2）还需要要切c-1刀，就是dp[c-1][i][j2]
//     水平切：枚举i2（i<i2<n）,切出来的高度就是i2-i，剩下的子矩形左上角（i2，j）还需要要切c-1刀，就是dp[c-1][i2][j]

// 都要保证，切出来那一块中需要有苹果，垂直的时候，j2，（i，j）；（n-1，j2-1） 有苹果
//                                  水平的时候，i2，（i，j）；（i2-1，n-1） 有苹果

// 返回：
// dp[k-1][0][0]

// 技巧： 判断是否有苹果可以利用二维数字前缀和

#include<iostream>
#include<vector>

using namespace std;

int ways(vector<string>& pizza, int k) {

    int n = pizza.size();
    int m = pizza[0].length();

    const int MOD = 1e9 + 7;

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            int curr = pizza[i - 1][j - 1] == 'A' ? 1 : 0;
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + curr;
        }
    }

    vector<vector<vector<int>>> dp(k, vector<vector<int>>(n, vector<int>(m, 0)));

    for (int c = 0; c < k;c++)
    {
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < m;j++)
            {
                // 不用切，判断是否有一种方案
                if(c==0){
                    // 判断左上角（i，j）和右下角（n，m）左闭右开区间是否存在A
                    int curr = sum[n][m] - sum[n][j] - sum[i][m] + sum[i][j];
                    dp[c][i][j] = curr >= 1 ? 1 : 0;
                    continue;
                }

                int res = 0;
                // 垂直切
                for (int j2 = j + 1; j2 < m; j2++)
                {
                    int curr = sum[n][j2] - sum[n][j] - sum[i][j2] + sum[i][j];
                    // 有苹果可以切
                    if(curr>0){
                        res = (res + dp[c - 1][i][j2]) % MOD;
                    }   
                }
                // 横着切
                for (int i2 = i + 1; i2 < n; i2++)
                {
                    int curr = sum[i2][m] - sum[i2][j] - sum[i][m] + sum[i][j];
                    if(curr>0){
                        res = (res + dp[c - 1][i2][j]) % MOD;
                    }
                }
                dp[c][i][j] = res;
            }
        }
    }
    return dp[k - 1][0][0];
}

int main(int argc, char const *argv[])
{
    vector<string> pizza = {"A..", "AAA", "..."};
    int k = 3;
    int ans = ways(pizza, k);
    cout << ans;
    return 0;
}
