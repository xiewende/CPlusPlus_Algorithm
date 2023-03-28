// 1574. 删除最短的子数组使剩余数组有序

// 解题思路：
// 子数组问题，删除的必须连续，类似之前的 前缀和+HashMap做法，但是前缀和在这里没有用处，有序也和前缀和没有关系，放弃
// 这题是子数组常解技能：双指针问题
// 为使得删除后有序，删除的位置有三个：左边，右边，中间的删除
// 先找出最长非递减前缀和最长非递减后缀 ： 记为：nums[0,..,i] ; nums[j,...,n-1]
// 若 i > j, 说明数组本身就是非递减的，返回0；
// 或者，我们可以选择删除右侧后缀，也可以选择删除左侧前缀，因此得到 ans = min(n - i - 1, j);
// 或者我们可以删除中间的，在 nums[0,...i]的位置 idx 中的 nums[idx] 在nums[j,...,n-1]寻找第一个其位置 idx1 中的 nums[dix1]；使得 nums[dix1] >= nums[idx]
// 那我们删除的子数字就是 nums[idx+1,..,idx1-1] 得到 ans=min(ans,idx1−idx−1)，是需要遍历 idx，每次在nums[j,...,n-1]找第一个大于等于值nums[idx] 的下边idx1，删除中间子数组就好；

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int len = arr.size();
    int i = 0;
    int j = len - 1;
    //最长非递减前缀
    while(i+1<len && arr[i]<= arr[i+1]){
        ++i;
    }
    //最长非递减后缀
    while(j-1>=0 && arr[j-1]<=arr[j]){
        --j;
    }
    // 整个数组非递减
    if(i>=j){
        return 0;
    }
    // 删除两边
    int ans = min(len - 1 - i, j);

    //遍历+寻找+更新答案
    for (int idx = 0, idx1 =j ; idx <= i; idx++)
    {   
        // 二分来找
        // int idx1 = lower_bound(arr.begin() + j, arr.end(), arr[idx]) - arr.begin();
        // ans = min(ans, idx1 - idx - 1);
        // 遍历来找
        while(idx1<len && arr[idx1]<arr[idx]){
            ++idx1;
        }
        ans = min(ans, idx1 - idx - 1);
    }
    return ans;
}

int main(){
    vector<int> arr{1,2,3,10,4,2,3,5};
    int ans = findLengthOfShortestSubarray(arr);
    cout << ans;
    return 0;
}
