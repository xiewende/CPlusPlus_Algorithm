//剑指 Offer 49. 丑数

//解题思路
// 任何一个丑数 = 前面某一个丑数*2，前面某一个丑数*3，前面某一个丑数*5 其中一个得到的
// dp[n]: 代表第 n+1 个丑数
// 转移方程
//     当索引 a,,b, ,c 满足以下条件时， dp[i] 为三种情况的最小值；
//     每轮计算 dp[i] 后，需要更新索引 a,b,c的值，使其始终满足方程条件。实现方法：分别独立判断 dp[i]
//     和 dp[a]*2 , dp[b]*3 , dp[c]*5 的大小关系，若相等则将对应索引 a , b , c 加 1 ；
//     dp[i] = min(dp[a]*2, dp[b]*3, dp[c]*5)
//     dp[i] = 取到 dp[a]*2, dp[b]*3, dp[c]*5 的最小值，等于最小的 下标 a，b，c需要 +1
// dp[0]=1 ，即第一个丑数为 1
// 返回dp[n−1] ，即返回第 n 个丑数

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int nthUglyNumber(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    int idx_a = 0;
    int idx_b = 0;
    int idx_c = 0;
    for (int i = 1; i < n; i++)
    {   
        // 分别求乘以 2 3 5的值
        int curr_a = dp[idx_a] * 2;
        int curr_b = dp[idx_b] * 3;
        int curr_c = dp[idx_c] * 5;
        // 取最小
        dp[i] = min(min(curr_a, curr_b), curr_c);
        // 相乘后的值等于最小的需要更新对应的下标
        idx_a = curr_a == dp[i] ? idx_a + 1 : idx_a;
        idx_b = curr_b == dp[i] ? idx_b + 1 : idx_b;
        idx_c = curr_c == dp[i] ? idx_c + 1 : idx_c;
    }
    return dp[n - 1];
}

int main(){
    int n = 10;
    int ans = nthUglyNumber(n);
    cout << ans;
    return 0;
}