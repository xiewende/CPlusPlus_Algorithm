// 1.第一题是给你一个数，判断这个数能不能组成一个图形。能的话就输出这个图形。
// 比如，数字10，对应图形如下：
// 01
// 02 09
// 03 10 08
// 04 05 06 07

#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> draw(int n){
    //判断是否能够组成三角形
    bool flag = false;
    int len = 0;
    for (int i = 1; i < n;i++)
    {
        if(i*(i+1)==2*n){
            len = i;
            break;
        }
    }
    if(len == 0){
        return {};
    }
    // 构造答案
    vector<vector<int>> ans(len, vector<int>(len));
    // 修改大小
    for (int i = 0; i < len;i++)
    {
        ans[i].resize(i+1);
    }

    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,-1}};
    vector<vector<bool>> visited(len, vector<bool>(len, false));
    for (int i = 0; i < len;i++)
    {
        for (int j = 0; j < len;j++)
        {
            if(j>i){
                visited[i][j] = true;
            }
        }
    }

    // 开始复制
    int x = -1;
    int y = 0;
    int idx = 0;
    for (int i = 1; i <= n;i++)
    {
       
        if(x + dirs[idx][0]>=len || x + dirs[idx][0]<0 || y + dirs[idx][1]>=len || y + dirs[idx][1]<0 || visited[x + dirs[idx][0]][y + dirs[idx][1]]==true){
            idx = (idx + 1) % 3;
        }
        x = x + dirs[idx][0];
        y = y + dirs[idx][1];

        ans[x][y] = i;
        visited[x][y] = true;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 15;
    vector<vector<int>> ans = draw(n);
    for(auto ves : ans){
        for(auto curr : ves){
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}

