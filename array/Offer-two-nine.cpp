// 剑指 Offer 29. 顺时针打印矩阵


#include<iostream>
#include<vector>
#include<utility>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return {};
    }
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ans(row * col, 0);
    vector<pair<int, int>> dirctions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    int idx_i = 0;
    int idx_j = 0;
    int idx_dir = 0;
    for (int i = 0; i < row * col;i++)
    {
        // 添加到答案里面
        ans[i] = matrix[idx_i][idx_j];
        visited[idx_i][idx_j] = true;

        // 判断下一个位置是否出界或者已经访问
        int next_i = idx_i + dirctions[idx_dir].first;
        int next_j = idx_j + dirctions[idx_dir].second;
        if(next_i < 0 || next_i >= row || next_j < 0 || next_j >=col || visited[next_i][next_j]){
            idx_dir = (idx_dir + 1) % 4;
        }

        idx_i += dirctions[idx_dir].first;
        idx_j = idx_j + dirctions[idx_dir].second;
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix{{1, 2, 3, 4}, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }};
    vector<int> ans = spiralOrder(matrix);
    for(auto item : ans){
        cout << item << " ";
    }
    return 0;
}