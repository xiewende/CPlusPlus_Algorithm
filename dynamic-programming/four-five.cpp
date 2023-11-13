// 45. 跳跃游戏 II

// 动态规划，类似最长递增子数组的概念

#include<iostream>
#include<vector>

using namespace std;


int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);

    for (int i = 1; i < n;i++)
    {
        int currS = n;
        for (int j = i - 1; j >= 0;j--)
        {
            int step = i - j;
            if( nums[j]>= step){
                currS = min(currS, dp[j]+1);
            }
        }
        dp[i] = currS;
    }

    return dp[n - 1];
}


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {2,3,0,1,4};
    int ans = jump(nums);
    cout << ans;
    return 0;
}

