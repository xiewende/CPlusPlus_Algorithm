// 剑指 Offer II 011. 0 和 1 个数相同的子数组

// 解题思路：前缀和+hash记录

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int findMaxLength(vector<int>& nums) {
    // key:前缀和；value：index
    unordered_map<int, int> visited = {{0,-1}};
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < nums.size();i++)
    {
        if(nums[i]==0){
            sum -= 1;
        }else
        {
            sum += 1;
        }
        if(visited.count(sum)>0){
            int curr = i - visited[sum];
            ans = max(ans, curr);
        }else
        {
            visited[sum] = i;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,1,0};
    int ans = findMaxLength(nums);
    cout<<ans;
    return 0;
}
