// 238. 除自身以外数组的乘积

// 因为有0的存在，所以不能采用除法

// 设置两个前缀积，分别左前缀积dpL，右前缀积dpR，这里需要两个遍历

// 在一次遍历，计算某个位置的左积*右积就是最终结果，不包括自己

#include<iostream>
#include<vector>

using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpL(n + 1, 0);
    vector<int> dpR(n + 1, 0);

    dpL[0] = 1;
    dpR[n] = 1;

    for (int i = 1; i < n; i++)
    {
        dpL[i] = dpL[i-1] * nums[i - 1];
    }

    for (int i = n-1; i >= 0; i--)
    {
        dpR[i] = dpR[i+1] * nums[i];
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < n;i++)
    {
        ans[i] = dpL[i] * dpR[i + 1];
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> ans = productExceptSelf(nums);
    for(auto tem : ans){
        cout << tem << " ";
    }
    return 0;
}
