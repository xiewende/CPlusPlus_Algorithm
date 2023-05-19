// 1072. 按列翻转得到最大值等行数

// 解题思路

// 判断翻转某些列后，一行的元素是一样的有两种情况
// 1、两行都是相同元素，例如 1001 和 1001；
// 2、两行对应位置都是相反元素，例如 1001 和 0110；
// 这两种情况通过翻转某些列都可以得到两行都是相同的元素，我们称这样的行为同质行
// 所以我们只需要统计矩阵中满足这样的行数（同质行）即可，
// 为了区别两行中都是相反的元素，我们定义一个改变就可以，
// 某行的第一个元素为0，整行不动，第一个元素为1，整行翻转即可，这样统一；了同质行。
// 用哈希来记录同质行的个数，然后遍历取最大。

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string, int> visited;
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        string s = "";
        for (int j = 0; j < col; j++)
        {
            if(matrix[i][0] == 0){
                s = s + to_string(matrix[i][j]);
            }else{
                s = s + to_string(matrix[i][j] ^ 1);
            }
        }
        visited[s]++;
    }
    int ans = 0;
    for (auto iter = visited.begin(); iter != visited.end(); iter++)
    {
        ans = max(ans, iter->second);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    int ans = maxEqualRowsAfterFlips(matrix);
    cout << ans;
    return 0;
}
