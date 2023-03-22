// 剑指 Offer 12. 矩阵中的路径

#include<iostream>
#include<vector>
#include<string>
#include<utility>

using namespace std;


bool backtrack(vector<vector<char>> board, string word, vector<vector<bool>> visit, int index ,int i, int j){
    
    int n = board.size();
    int m = board[0].size();

    if(board[i][j] != word[index]){
        return false;
    }

    if (index == word.size() -1 )
    {
        return true;
    }
    visit[i][j] = true;
    bool result = false;
    vector<pair<int, int>> dirctions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 四个方向
    for(auto dirction : dirctions){
        //更新搜索位置
        int new_i = i + dirction.first;
        int new_j = j + dirction.second;
        
        // index 越界，直接剪枝
        if(new_i>=0 && new_i<n && new_j>=0 && new_j<m){
            if(!visit[new_i][new_j]){
                bool flag = backtrack(board, word, visit, index+1, new_i, new_j);
                if(flag){
                    result = flag;
                    break;
                }
         }
        }
    }
    visit[i][j] = false;
    return result;
}

bool exist(vector<vector<char>>& board, string word) {

    int n = board.size();
    int m = board[0].size();
    bool ans = false;
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {   
            // 按照DFS的方式查找
            ans = backtrack(board, word, visit, 0, i, j);
            if(ans){
                return ans;
            }
        }
    }
    return ans;
}

int main(){

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    //vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
    string word = "ABCCED";
    bool ans = exist(board, word);
    cout << ans;
    return 0;
}