// 2488. 统计中位数为 K 的子数组

// 由题意知道 nums[n]数组中的值是1-n，并且是不重复的，给定的k也是在1-n当中，
// 当某个子数组是以k为中位数的时，左边小于k的个数 = 右边大于k的个数  或者  左边小于k的个数 + 1 = 右边大于k的个数

// 所以我们取 小于k的值为 -1，大于k的值为 1，

// 假定 sum[i] 为 nums[i] 的前缀和，K在 nums数组的下标为 kIndex，
// 那么满足以 k 为中位数的子数组满足 -1 < left < kIndex <= right 且 sum[right] - sum[left] = 0 or 1 

// 那么就是转换为了 子数组和问题，也就是熟悉的 数组 前缀和+HashMap 来解决

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string.h>
// #include<string>

using namespace std;


int sign(int num) {
    if (num == 0) {
        return 0;
    }
    return num > 0 ? 1 : -1;
}

int countSubarrays(vector<int>& nums, int k) {

    int kIndex = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == k){
            kIndex = i;
            break;
        }
    }

    int ans = 0;
    int sum = 0;
    unordered_map<int, int> visit{{0,1}};

    for (int i = 0; i < nums.size();i++)
    {
        sum += sign(nums[i] - k);
        if(i < kIndex){
            visit[sum]++;
        }else{
            int pre0 = visit[sum];
            int pre1 = visit[sum - 1];
            ans = ans + pre0 + pre1;
        }
    }

    return ans;
}

int countSubarrays1(vector<int> &nums, int k) {
    int pos = find(nums.begin(), nums.end(), k) - nums.begin();
    int n = nums.size(), cnt[n * 2];
    // memset(cnt, 0, sizeof(cnt));
    fill_n(cnt, n *2, 0); //首选 前两个参数是指针地址
    cnt[n] = 1;
    for (int i = pos - 1, x = n; i >= 0; --i) { // 从 pos-1 开始累加 x
        x += nums[i] < k ? 1 : -1;
        ++cnt[x];
    }

    int ans = cnt[n] + cnt[n - 1];
    for (int i = pos + 1, x = n; i < n; ++i) { // 从 pos+1 开始累加 x
        x += nums[i] > k ? 1 : -1;
        ans += cnt[x] + cnt[x - 1];
    }
    return ans;
}

int main(){
    vector<int> nums{3, 2, 1, 4, 5};
    int k = 4;
    int ans = countSubarrays(nums, k);
    cout << ans;
    return 0;
}
