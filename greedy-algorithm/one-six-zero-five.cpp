// 1605. 给定行和列的和求可行矩阵

// 解题思路：贪心算法

// 很明显利用 暴力方法 OR 回溯法肯定是可以计算，但是计算量比较大，

// 由于题目要求的是满足的一个矩阵就好，我们只需要将每个位置的值尽量设置的大点，使其满足行列和，然后剩余的行和列就可以直接填 0 的。（贪心的做法）

// 假设 i行（j列）满足了行和 (列和) 那么剩余的 行和列也是满足的；或者说，从矩阵左上角出发，每次要么去掉一行，要么去掉一列


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> ans(n, vector<int>(m, 0)); // n*m的初始值全为0的二维举证

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            ans[i][j] = min(rowSum[i], colSum[j]); // 找满足行列和的最大值
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
        }
    }

    return ans;
}

vector<vector<int>> restoreMatrix1(vector<int>& rowSum, vector<int>& colSum) {

    int n = rowSum.size();
    int m = colSum.size();
    vector<vector<int>> ans(n, vector<int>(m, 0)); // n*m的初始值全为0的二维举证
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        int rs = rowSum[i];
        int cs = colSum[j];
        if(rs < cs ){  // 去掉 i 行，往下走
            ans[i][j] = rs;
            colSum[j] -= rs;
            i++;
        }else{        // 去掉 j 列，往左走
            ans[i][j] = cs;
            rowSum[i] -= cs;
            j++;
        }
    }

    return ans;
}


int main(){
    vector<int> rowSum{3,8};
    vector<int> colSum{4,7};
    vector<vector<int>> ans = restoreMatrix1(rowSum, colSum);

    for(auto ves : ans){
        for(auto value : ves){
            cout << value << ",";
        }
        cout << endl;
    }
}