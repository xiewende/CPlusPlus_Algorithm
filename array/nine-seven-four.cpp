// 974. 使数组和能被 K 整除

// 解题思路 ： 前缀和 + HashMap
// HsahMap ==> key: Sum % P  value：count（个数，初始1）

// 取余的一个定理： 同余： 若（x-y） % p == 0，则 x 和 y 对 模 p 同余 

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


int minSubarray(vector<int>& nums, int k) {

    int ans = 0;
    int sum = 0;
    unordered_map<int, int> last;
    last[0] = 1;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        sum = sum + nums[i];
        int target = (sum % k + k) % k; // +k 是为了防止负值  最后的 %k 是 正余数 +k>k 所以再次取余
        cout << target << endl;
        if (last.count(target)) {
            ans = ans + last[target];
        }
        last[target]++;
    }
    return ans;
}

int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    for(auto num : nums){
        cout << num <<",";
    }

    cout << endl;

    int k = 5;

    int ans = minSubarray(nums, k);

    cout << ans << endl;
}
