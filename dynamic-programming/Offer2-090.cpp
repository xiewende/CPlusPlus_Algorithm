// 剑指 Offer II 090. 房屋偷盗2

// 解题思路：动态规划，

// dp[i]:代表小偷到第i家的时候的最大值，两个状态（偷i家；不偷i家）
// dp[i] = max(dp[i-2]+nums[i], dp[i-1]) 偷i家；不偷i家

// 但是此时 首位算是连接的，此时我们只需要定义两个dp数组，
// dp0: 代表从【0，length-2】中偷盗最大值
// dp1：代表【1，length-1】中的最大值
// 此时我们怎么偷都不会首位相连
// 返回 man(dp0[length-2], dp1[length-1])

#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
    int length = nums.size();
    if(length == 1){
        return nums[0];
    }

    // 由于偷了最后一个，第一个就不能投，偷了第一个，最后一个就不能偷，那么使用两个dp,一个dp从第一个开始，一个dp从第二个开始，最后判断哪个最大。
    vector<int> dp0(length,0); // [0,length-2] 偷0不偷尾
    vector<int> dp1(length,0); // [1,length-1] 不偷0偷尾巴
    dp0[0] = nums[0];
    dp0[1] = nums[0];

    dp1[1] = nums[1];

    for(int i =2; i<length; i++){
        dp0[i] = max(dp0[i-2]+nums[i],dp0[i-1]);
        dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
    }

    return max(dp0[length-2],dp1[length-1]);
    
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    int ans = rob(nums);
    cout << ans;
    return 0;
}