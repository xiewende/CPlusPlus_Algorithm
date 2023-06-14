// 2352. 相等行列对

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool check(vector<vector<int>>& grid, int row, int col){
    for (int i = 0; i < grid.size();i++)
    {
        if(grid[row][i] != grid[i][col]){
            return false;
        }
    }
    return true;
}

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int, vector<int>> stored; // 存储行。key：值，values：列index
    for (int i = 0; i < n;i++)
    {
        stored[grid[0][i]].emplace_back(i);
    }
    int ans = 0;
    // 遍历行
    for (int j = 0; j < n;j++)
    {
        int curr = grid[j][0];
        for(auto same_idx : stored[curr]){
            bool is_same = check(grid, j, same_idx);
            if(is_same){
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    int ans = equalPairs(grid);
    cout << ans;
    return 0;
}
