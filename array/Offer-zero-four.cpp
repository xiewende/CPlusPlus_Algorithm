// 剑指 Offer 04. 二维数组中的查找

#include<iostream>
#include<vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

    int n = matrix.size();

    if(n<1){
        return false;
    }
    int m = matrix[0].size();


    int row = n - 1;
    int col = 0;

    while(row>=0 && col<m){
        if(matrix[row][col] == target)
        {
            return true;
        }else if (matrix[row][col] < target)
        {
            col++;
        }else
        {
            row--;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix{{1,   4,  7, 11, 15},
                                {2,   5,  8, 12, 19},
                                {3,   6,  9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};

    int target = 20;

    bool ans = findNumberIn2DArray(matrix, target);
    cout << ans;
    return 0;
}