// 剑指 Offer II 088. 爬楼梯的最少成本

#include<iostream>
#include<vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {

    vector<int> dp(cost.size()+1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= cost.size();i++)
    {
        dp[i] = min(dp[i - 1]+cost[i-1], dp[i - 2]+cost[i-2]);
    }

    return dp[cost.size()];
}

int main(){
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int ans = minCostClimbingStairs(cost);
    cout << ans;
    return 0;
}