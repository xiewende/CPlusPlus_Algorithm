#include<iostream>
#include<vector>

using namespace std;


int getIdx(vector<int> &nums, int left, int right){
    int val = nums[left];
    while(left<right){
        // 右找小
        while(left<right && nums[right]>=val){
            right--;
        }
        //换
        nums[left] = nums[right];
        // 左找大
        while(left<right && nums[left]<val){
            left++;
        }
        // 换
        nums[right] = nums[left];
    }
    // 枢纽换
    nums[left] = val;
    return left;
}

void quickSort(vector<int> &nums, int begin, int end){
    if(begin<end){
        int idx = getIdx(nums, begin, end);
        quickSort(nums, begin, idx - 1);
        quickSort(nums, idx + 1, end);
    }
}


int main(int argc, char const *argv[])
{
    
}

