// 剑指 Offer II 007. 数组中和为 0 的三个数

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &ans, vector<int> &curr, vector<int> &nums, int sum, int index){
    if(curr.size() == 3 && sum == 0){
        ans.push_back(curr);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {   
        if( (i!=index && nums[i]==nums[index]) || (i!=0 && curr.empty() && nums[i]==nums[i-1])){
            continue;
        }
        curr.push_back(nums[i]);
        dfs(ans, curr, nums, sum+nums[i], i+1);
        curr.pop_back();
    }
    return;
}

vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    vector<int> curr;
    dfs(ans, curr, nums, 0, 0);
    return ans;
}


vector<vector<int>> threeSum1(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && nums[first] == nums[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -nums[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && nums[second] == nums[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && nums[second] + nums[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (nums[second] + nums[third] == target) {
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {-4,-1,-1,0,1,2}; // ,,,   -4,-1,-1,0,1,2
    vector<vector<int>> ans = threeSum(nums);
    for(auto currs : ans){
        for(auto curr : currs){
            cout << curr << " ";
        }
        cout << endl;
    }

    return 0;
}
