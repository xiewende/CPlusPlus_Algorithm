
// 矩阵中的局部最大值

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int length = row - 3 + 1;
    vector<vector<int>> ans(length, vector<int>(length,0));

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            for (int x = i; x < i + 3; x++)
            {
                for (int y = j; y < j + 3; y++)
                {
                    ans[i][j] = max(ans[i][j], grid[x][y]);
                }
            }
        }
    }

    return ans;
}

int main(){
    // vector<vector<int>> grid(4,vector<int>(4,0)); // 生成4x4全为0的二维数组
    vector<vector<int>> grid = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    int row = grid.size();
    int clo = grid[0].size();
    cout << row << clo << endl;
    // for(auto tem: grid){
    //     for(int a: tem){
    //         cout << a;
    //     }
    // }
    // cout << grid[6][1];
    vector<vector<int>> ans; 
    ans = largestLocal(grid);
    for(auto tem: ans){
        for(int a: tem){
            cout << a;
        }
    }
}