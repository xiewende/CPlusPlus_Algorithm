// 排序算法大总结

#include<iostream>
#include<vector>

using namespace std;


// 快排

int patition(vector<int>& nums, int left, int right){
    // 以当前数组的第一个元素作为中枢pivot
    int pivot = nums[left];
    while(left < right){
        //右开始找比中枢小
        while(left<right && nums[right]>=pivot)
        {
            right--;
        }
        // 找到换位置
        nums[left] = nums[right];
        // 左开始找比中枢大
        while (left<right && nums[left]<pivot)
        {
            left++;
        }
        // 换位置
        nums[right] = nums[left];
    }
    // left=right，这个位置就是中枢应该放置的位置
    nums[left] = pivot;
    // 返回中枢的最终位置
    return left;
}
void quickSort(vector<int>& nums, int left, int right){
    // 跳出递归的条件
    // nums.emplace_back
    if(left < right){ 
        // partition就是划分操作，将nums划分成满足条件的两个子表
        // 返回的 idx 就是选取参照点应该放置的位置
        int idx = patition(nums, left, right);
        // 左右两个子表进行递归排序
        quickSort(nums, left, idx-1);
        quickSort(nums, idx+1, right);
    }
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {2,4,3,1,6,8,4};
    quickSort(nums, 0, nums.size()-1);
    for(auto curr: nums){
        cout << curr << " ";
    }
    return 0;
}
