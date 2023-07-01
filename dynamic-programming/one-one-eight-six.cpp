// 1186. 删除一次得到子数组最大和

// 解题思路：状态问题，分离状态，动态规划

// 定义：dp[i][k]为以arr[i]结尾的数组，仅删除k次的最大子数组和，其中k=0，1

// 对于dp[i][0], 遇到 arr[i]: dp[i][0] = max(dp[i-1][0]+arr[i], arr[i])   不能删除的情况就是当前元素或者是之前的+当前元素
// 对于dp[i][0]，遇到 arr[i]: dp[i][1] = dp[i-1][0], 删除当前元素，则前面元素没有删除
//                           dp[i][1] = dp[i-1][1] + arr[i], 不删除当前元素，之前的数组已经删除了一个  

#include<iostream>
#include<vector>

using namespace std;

int maximumSum(vector<int>& arr) {
    int n = arr.size();
    // 两个dp数组
    vector<int> dp_0(n, 0);
    vector<int> dp_1(n, 0);
    // 初始化
    dp_0[0] = arr[0];
    dp_1[0] = 0;
    int ans = dp_0[0];
    // int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        // 顺序可变
        dp_0[i] = max(dp_0[i-1]+arr[i], arr[i]);
        dp_1[i] = max(dp_0[i - 1], dp_1[i - 1] + arr[i]);
        ans = max(ans, max(dp_0[i], dp_1[i]));
    }
    return ans;
}

// 压缩数组
int maximumSum(vector<int>& arr) {
    int n = arr.size();
    // 两个dp数组
    int dp_0 = arr[0];
    int dp_1 = 0;
    // 初始化
    int ans = dp_0;
    // int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        // 顺序不可变
        dp_1 = max(dp_0, dp_1 + arr[i]);
        dp_0 = max(dp_0+arr[i], arr[i]);
        ans = max(ans, max(dp_0, dp_1));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {-1,-1,-1,-1};
    int ans = maximumSum(arr);
    cout << ans;
    return 0;
}
