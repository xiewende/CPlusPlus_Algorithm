// 1043. 分隔数组以得到最大和

// 解题思路：动态规划

// dp[i]：以 i 结尾的数组划分最长的长度为 k 的最大值，

// 遍历到 arr[i] ：arr[i] 为一个分组
//                arr[i] arr[i-1] 为一个分组
//                arr[i] arr[i-1] arr[i-2]  为一个分组
//                arr[i] arr[i-1] arr[i-2] arr[i-3] 为一个分组 
//                 ....
//                分组长度最长为 k 即可，也就是遍历上述分组的可能情况，取最大值，需要记录上述某一分组的最大值

// 状态转移方程：
// dp[i] = max（dp[i], dp[j]+(i-j)*maxValue）  其中需要遍历 j： i-k <= j < i

// 返回 dp[len];

#include<iostream>
#include<vector>

using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int len = arr.size();
    vector<int> dp(len+1, 0);
    // dp[0] = arr[0];
    for (int i = 1; i <= len; i++)
    {
        // 新的数组单独一个组
        int maxValue = arr[i-1];
        dp[i] = dp[i - 1] + arr[i-1]; 

        //新的数字和前面的 1，2.。k-1个数分别分为一组，取最大， 长度最长为 k，
        for (int j = i - 1; j > i - k && j>0; j--)
        {
            maxValue = max(maxValue, arr[j-1]);
            dp[i] = max(dp[i], dp[j - 1] + maxValue * (i - j + 1));
        }
    }
    return dp[len];
}

int maxSumAfterPartitioning1(vector<int>& arr, int k) {
    int len = arr.size();
    vector<int> dp(len+1, 0);
    // dp[0] = arr[0];
    for (int i = 1; i <= len; i++)
    {
        // 分组的最大值
        int maxValue = arr[i-1];
        //新的数字和前面的 1，2.。k-1个数分别分为一组，取最大， 长度最长为 k，
        for (int j = i - 1; j >= i - k && j>=0; j--)
        {
            dp[i] = max(dp[i], dp[j] + maxValue * (i - j));
            maxValue = max(maxValue, arr[j-1]);
        }
    }
    return dp[len];
}

int main(){
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    int ans = maxSumAfterPartitioning1(arr, k);
    cout << ans;
    return 0;
}