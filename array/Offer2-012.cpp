// 剑指 Offer II 012. 左右两边子数组的和相等

#include<iostream>
#include<vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int len = nums.size();
    vector<int> sum(len+2, 0);
    for(int i=0;i<len;i++){
        sum[i+1] = sum[i] + nums[i];
    }

    for(int i=0;i<len;i++){
        if(sum[i] == sum[len]-sum[i+1]){
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int ans = pivotIndex(nums);
    cout << ans;
    return 0;
}
