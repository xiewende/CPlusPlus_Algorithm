// 525. 连续数组
// 给定一个二进制数组 nums , 
// 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int findMaxLength(vector<int>& nums) {

    unordered_map<int, int> visit{{0, -1}};
    int length = nums.size();
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < length;i++)
    {
        int tem = nums[i] == 1 ? 1 : -1;
        sum += tem;
        if(visit.count(sum)){
            int index = visit[sum];
            ans = max(ans, i - index);
        }else
        {
            visit[sum] = i;
        }
    
    }
    return ans;
}

int main(){
    vector<int> nums{0,1,0};
    int ans = findMaxLength(nums);
    cout << ans << endl;
}
