// 剑指 Offer 03. 数组中重复的数字

#include<iostream>
#include<vector>

using namespace std;

int findRepeatNumber(vector<int>& nums) {

    int length = nums.size();
    vector<int> visit(length, 0);
    for (int i = 0; i < length; i++)
    {
        visit[nums[i]]++;
        if(visit[nums[i]]>1){
            return nums[i];
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{

    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    int ans = findRepeatNumber(nums);
    cout << ans;
    return 0;
}
