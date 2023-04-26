// 1031. 两个非重叠子数组的最大和

// 动态规划

// 根据题意：返回其中 maxSumTwoNoOverlap_alone(nums,firstLen,secondLen) maxSumTwoNoOverlap_alone(nums,secondLen,firstLen) 的最大值

// dp[i]: 以nums[i]结束的值的最大子数组 和

// left_sum: 靠左边长为 firstLen 的子数组和
// right_sum: 靠右边长为 secondLen 的子数组和

// 遍历 i ：
// 1、right_sum 不包含 nums[i]，则 dp[i] = dp[i-1];
// 2、right_sum 包含 nums[i]， 
//     更新 right_sum 的值
//     此时遍历前面部分更新 left_sum 值会有多种选择，取其最大值 max_left_sum，则 dp[i] = right_sum + max_left_sum
// 3、则状态转移方程：dp[i] = max(dp[i-1], right_sum + max_left_sum)  

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int maxSumTwoNoOverlap_alone(vector<int>& nums, int firstLen, int secondLen) {
    int len = nums.size();
    if(len < firstLen + secondLen){
        return 0;
    }
    vector<int> dp(len, 0);

    int sum_left = accumulate(nums.begin(), nums.begin() + firstLen, 0);
    int sum_right = accumulate(nums.begin()+firstLen, nums.begin() + firstLen + secondLen, 0);
    dp[firstLen + secondLen - 1] = sum_left + sum_right;

    for (int i = firstLen + secondLen; i < len; i++)
    {
        int curr = dp[i - 1];
        int idx_right = i - secondLen;
        sum_right = sum_right + nums[i] - nums[idx_right];
        curr = max(curr, sum_left + sum_right);
        int curr_sum_left = sum_left;
        for (int j = firstLen; j<=idx_right; j++)
        {
            curr_sum_left = curr_sum_left + nums[j] - nums[j - firstLen];
            curr = max(curr, curr_sum_left + sum_right);
        }
        dp[i] = curr;
    }
    return dp[len - 1];
}


int maxSumTwoNoOverlap_alone1(vector<int>& nums, int firstLen, int secondLen) {
    int len = nums.size();
    if(len < firstLen + secondLen){
        return 0;
    }
    vector<int> dp(len, 0);

    int sum_left = accumulate(nums.begin(), nums.begin() + firstLen, 0);
    int sum_right = accumulate(nums.begin()+firstLen, nums.begin() + firstLen + secondLen, 0);
    dp[firstLen + secondLen - 1] = sum_left + sum_right;
    int max_sum_left = sum_left;
    for (int i = firstLen + secondLen, j=firstLen; i < len; i++,j++)
    {
        sum_left = sum_left + nums[j] - nums[j - firstLen];
        max_sum_left = max(max_sum_left, sum_left);
        sum_right = sum_right + nums[i] - nums[i-secondLen];
        dp[i] = max(dp[i-1], sum_right + max_sum_left);
    }
    return dp[len - 1];
}

int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int ans1 = maxSumTwoNoOverlap_alone1(nums, firstLen, secondLen);
    int ans2 = maxSumTwoNoOverlap_alone1(nums, secondLen, firstLen);
    return max(ans1, ans2);
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {0,6,5,2,2,5,1,9,4};
    int firstLen = 1;
    int secondLen = 2;
    int ans = maxSumTwoNoOverlap(nums, firstLen, secondLen);
    cout << ans;
    return 0;
}
