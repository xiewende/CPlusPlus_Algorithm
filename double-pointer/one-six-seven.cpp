// 167. 两数之和 II - 输入有序数组

// 解题思路：双指针

#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;
    while(i<j){
        int sum = numbers[i] + numbers[j];
        // 和大，则j--，减小最大值
        if(sum>target){
            j--;
        }else if(sum<target){
            // 和小，则i++，增大最小值
            i++;
        }else{
            return {i+1, j+1};
        }
    }
    return {};
}

int main(int argc, char const *argv[])
{
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(numbers, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}
