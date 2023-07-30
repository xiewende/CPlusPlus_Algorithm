// 2500. 删除每行中的最大值

// 解题思路：数组排序即可

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int deleteGreatestValue(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n;i++)
    {
        sort(grid[i].begin(), grid[i].end());
    }
    int ans = 0;
    // 先遍历列
    for (int j = m - 1; j >= 0;j--)
    {
        int currMax = 0;
        // 再遍历行
        for (int i = 0; i < n;i++)
        {
            currMax = max(currMax, grid[i][j]);
        }
        ans += currMax;
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {{1,2,4},{3,3,1}};
    int ans = deleteGreatestValue(grid);
    cout << ans;
    return 0;
}