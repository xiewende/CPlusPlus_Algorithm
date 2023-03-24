// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

#include<iostream>
#include<vector>

using namespace std;

vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int left = 0, right = n - 1;
    for (auto & num : nums) {
        if (num % 2 == 1) {
            res[left++] = num;
        } else {
            res[right--] = num;
        }
    }
    return res;
}