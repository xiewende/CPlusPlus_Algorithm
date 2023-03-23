// 1630. 等差子数组

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkSub(vector<int> nums, int left, int right){
    if(left == right-1){
        return true;
    }
    // 先[begin,end]区间排序排序
    sort(nums.begin()+left , nums.begin()+right+1);
    int cha = nums[left + 1] - nums[left];
    int idx = left;
    while(idx < right ){
        if((nums[idx+1] - nums[idx]) != cha){
            return false;
        }
        idx = idx + 1;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

    int n = nums.size();
    int m = l.size();
    vector<bool> ans(m, false);
    // int left = 0;
    for (int i=0; i<m; i++)
    {
        int left = l[i];
        int end = r[i];
        ans[i] = checkSub(nums, left, end);
    }
    return ans;
}

int main(){
    vector<int> nums{4,6,5,9,3,7};
    vector<int> l{0, 0, 2};
    vector<int> r{2, 3, 5};
    vector<bool> ans = checkArithmeticSubarrays(nums, l, r);
    for(bool an : ans){
        cout << an << endl;
    }
    return 0;
}