// 2679. 矩阵中的和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

// bool cmp1(vector<int>& a, vector<int>& b){
//     return a[0] > b[0];
// }

int matrixSum(vector<vector<int>>& nums) {
    int row = nums.size();
    int col = nums[0].size();
    for (int i = 0; i < row;i++)
    {
        sort(nums[i].begin(), nums[i].end(), cmp);
    }
    int ans = 0;
    // sort(nums.begin(), nums.end(), cmp1);
    for (int j = 0; j < col; j++)
    {
        int curr = 0;
        for (int i = 0; i < row; i++)
        {
            curr = max(curr, nums[i][j]);
        }
        ans += curr;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{7,2,1}, {1,2,3}, {2,4,6}, {6,3,5}};
    int ans = matrixSum(nums);
    cout << ans;
    return 0;
}
