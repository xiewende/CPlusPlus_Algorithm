// 1590. 使数组和能被 P 整除

// 解题思路 ： 前缀和 + HashMap
// HsahMap ==> key: Sum % P  value：下标 index  求最短子数组需要index

// 取余的一个定理： 同余： 若（x-y） % p == 0，则 x 和 y 对 模 p 同余 

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
