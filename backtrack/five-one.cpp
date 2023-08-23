// 51. N 皇后

#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 判断x，y位置是否可以放置
bool isPush(vector<vector<char>> &grap, int x, int y){
    int n = grap.size();
    for (int i = 0; i < x;i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(grap[i][j] == 'Q' &&(j==y || abs(x-i)==abs(y-j))){
                return false;
            }
        }
    }
    return true;
}

// char TO string
vector<string> toStr(vector<vector<char>> &grap){
    int n = grap.size();
    vector<string> ans(n);
    for (int i = 0; i < n;i++)
    {
        string s = "";
        for (int j = 0; j < n;j++)
        {
            s += grap[i][j];
        }
        ans[i] = s;
    }
    return ans;
}

void dfs(vector<vector<string>> &ans, vector<vector<char>> &grap,  int row){
    if(row == grap.size()){
        vector<string> curr = toStr(grap);
        ans.emplace_back(curr);
        return;
    }
    for (int col = 0; col < grap.size(); col++)
    {
       if(isPush(grap, row , col)){
            // 可以放
            grap[row][col] = 'Q';
            dfs(ans, grap, row+1);
            // 状态恢复
            grap[row][col] = '.';
       }
    }
}

vector<vector<string>> solveNQueens(int n) {
    // 先创建一个棋盘，没有皇后
    vector<vector<char>> grap(n, vector<char>(n));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            grap[i][j] = '.';
        }
    }
    vector<vector<string>> ans;
    dfs(ans, grap, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size();i++)
    {
        for (int j = 0; j < ans[0].size();j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout << "next: "<<endl;
    }
    return 0;
}
