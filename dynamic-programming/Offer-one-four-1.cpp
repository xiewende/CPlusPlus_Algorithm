// 剑指 Offer 14- I. 剪绳子

// 解题思路，可以分解成子问题求最解，所以采用动态规划
// 一段绳子可以切分为至少 2 段，
// dp[i]: 代表长为 n 的绳子切成 m 段后的最大乘积
// dp[0] = dp[1] = 0;
// 当 i >= 2时候 假设对正整数 i 拆分出的第一个正整数是 j（1≤j<i） ，则有以下两种方案：
// 将 i 拆分成 j 和 i−j 的和，且 i−j 不再拆分成多个正整数，此时的乘积是 j × (i−j) ；
// 将 i 拆分成 j 和 i−j 的和，且 i−j 继续拆分成多个正整数，此时的乘积是 j × dp[i−j]。
// 因此需要遍历 j 才可以得到最大值
// 状态转移方程为：
// dp[i] = max【max(j*(i-j), j*dp[i-j])】； 其中 j < i 

// 当 n>=4的时候，必须剪一刀才可以得到最优解，所以有
// dp[i] = max【dp[j] * dp[i-j]】 i>=4

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cuttingRope(int n) {
    vector<int> dp(n+1, 1);
    for (int i=2; i<=n; i++)
    {
        int curr = 0;
        for (int j = 1; j < i;j++){
            curr = max(curr, max(dp[j] * (i-j), (i-j) * j));
        }
        dp[i] = curr;
    }
    return dp[n];
}

int main(){
    int ans = cuttingRope(8);
    cout << ans;
    return 0;
}