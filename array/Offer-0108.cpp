// 面试题 01.08. 零矩阵

#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int len_row = matrix.size();
    int len_col = matrix[0].size();
    //标记数组
    vector<vector<bool>> visited(len_row, vector<bool>(len_col, true));
    for (int i = 0; i < len_row; i++)
    {
        for (int j = 0; j < len_col; j++)
        {
            if(matrix[i][j] == 0 && visited[i][j]){
                //每行
                for (int col = 0; col < len_col; col++)
                {
                    if(matrix[i][col] !=0){
                        matrix[i][col] = 0;
                        visited[i][col] = false;
                    }
                }
                //每列
                for (int row = 0; row < len_row; row++)
                {
                    if(matrix[row][j] !=0){
                        matrix[row][j] = 0;
                        visited[row][j] = false;
                    }
                }
            }
        }
    }
}

void setZeroes1(vector<vector<int>>& matrix) {
    int len_row = matrix.size();
    int len_col = matrix[0].size();
    //一维标记数组
    vector<bool> row(len_row,false);
    vector<bool> col(len_row,false);

     for (int i = 0; i < len_row; i++) {
        for (int j = 0; j < len_col; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < len_row; i++) {
        for (int j = 0; j < len_col; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}