// 1590. 使数组和能被 P 整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。

// 解题思路 ： 前缀和 + HashMap
// HsahMap ==> key: Sum % P  value：下标 index  求最短子数组需要index

// 取余的一个定理： 定理一同余： 若（x-y） % p == 0，则 x 和 y 对 模 p 同余 
//                 定理二：    若 (z-y) % p ==x 则 y % p  == （z-x） % p

// sum[i]: 代表到数组 i 位置的数组前缀和； sum[n]: 数组全部和=x
// 定理一
// 根据题意，要使移除子数组后剩余数组能够被 p 整除，【sum[n] - (某个子数组)】 % p == 0 
//                                           ==》sum[n] % p  == (某个子数组)】 % p
//                                           ==》sum[n] % p  == 【sum[i]-sum[j]】 % p
//                                           ==》x  == 【sum[i]-sum[j]】 % p  ( i > j )
//定理二 
//                                              【sum[i]-sum[j]】 % p = x      
//                                               sum[j] % x == 【sum[i] - x】 % p                                                                     


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int minSubarray(vector<int>& nums, int p) {

    int k = 0;
    for (int& x : nums) {
        k = (k + x) % p;
    }
    if (k == 0) {
        return 0;
    }
    unordered_map<int, int> last;
    last[0] = -1;
    int n = nums.size();
    int ans = n;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur = (cur + nums[i]) % p;
        int target = (cur - k + p) % p;
        if (last.count(target)) {
            ans = min(ans, i - last[target]);
        }
        last[cur] = i;
    }
    return ans == n ? -1 : ans;
}

int main(){
    vector<int> nums = {3,1,4,2};
    for(auto num : nums){
        cout << num << endl;
    }

    int p = 6;

    int ans = minSubarray(nums, p);

    cout << ans << endl;
}
