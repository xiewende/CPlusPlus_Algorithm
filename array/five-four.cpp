//54. 螺旋矩阵

#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // 定义四个方向，往左，往下，往右，往上依次循环
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int idx = 0;

    // p判断是否遍历过，若是遍历过的需要扭转方向
    vector<vector<bool>> seen(n, vector<bool>(m, false));

    // 记录答案
    vector<int> ans(n * m, 0);
    int x = 0;
    int y = -1;
    for (int i = 0; i < n * m;i++)
    {
        // 每次遍历该方向的下一个位置是否满足没有遍历的情况且判断是否需要改变方向
        if(x+dirs[idx][0]>=n || x+dirs[idx][0]<0 || y+dirs[idx][1]>=m || y+dirs[idx][1]<0 || seen[x+dirs[idx][0]][y+dirs[idx][1]]){
            idx = (idx + 1) % 4;
        }
        // 下一个x y坐标
        x = x + dirs[idx][0];
        y = y + dirs[idx][1];
        // 改变答案
        ans[i] = matrix[x][y];
        // 记录遍历过的点
        seen[x][y] = true;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(auto num:ans){
        cout << num<<" ";
    }
    return 0;
}
