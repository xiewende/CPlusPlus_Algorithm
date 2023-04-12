// 面试题 01.07. 旋转矩阵
// 解题思路 找规律

// 1、起点【i，j】 旋转90°在【j，n-i-1】再旋转90°在【n-i-1，n-j-1】再旋转90°在【n-j-1，i】
//    这四个点，若旋转90°，需要互相取代其位置

// 2、上下镜像交换值 再 对角线交换值 得到最终结果

#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    //遍历左上角的值，依次替换四个位置即可
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < (n + 1) / 2;j++)
        {
            int tem = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tem;
        }
    }
}

void rotate1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    //上下 水平轴翻转
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    //对角线反转
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}