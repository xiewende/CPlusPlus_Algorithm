#include<iostream>
#include<vector>

using namespace std;


int count(vector<vector<char>>& grap){
    int n = grap.size();
    int m = grap[0].size();
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 1; i < n;i++)
    {
        for (int j = 1; j < m;j++)
        {
            if(grap[i][j]=='.'){
                continue;
            }
            // 正的, 往左找第一个X
            int b_j = j-1;
            while(b_j>=0){
                if(grap[i][b_j] == 'X'){
                    int dis = j - b_j; // 1
                    int b_i = i - dis;
                    if(b_i>=0 && grap[b_i][b_j] == 'X' && grap[b_i][j] == 'X'){
                        ans++;
                    }
                }
                b_j--;
            }

            // 斜的，往左上找一个X
            int b_i = i - 1;
            b_j = j - 1;
            while(b_i>=0 && b_j>=0){
                if(grap[b_i][b_j] == 'X'){
                    int dis = i - b_i;
                    int bb_i = i - 2 * dis;
                    int bb_j = j + dis;
                    if(bb_i>=0 && bb_j<m && grap[bb_i][j]=='X' && grap[b_i][bb_j] == 'X'){
                        ans++;
                    }
                }
                b_i--;
                b_j--;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> grap = {{'X', 'X', '.', '.','.'}, {'X', 'X', 'X', '.', 'X'}, {'.', 'X', '.', 'X','X'}, {'.', '.', 'X', 'X','X'}, {'X','X','X','X','X'}};
    int ans = count(grap);
    cout << ans;

    return 0;
}
