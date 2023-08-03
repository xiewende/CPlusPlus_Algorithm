// 874. 模拟行走机器人

// 解题思路：数组模拟即可

#include<iostream>
#include<vector>
#include<unordered_set>
#include<utility>

using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // 设定障碍点
    unordered_set<int> obSet;
    // 二维坐标记录问题
    // 可以利用 x*m+y 的方法来记录存储，实现坐标转换 m 为二维矩阵的行数
    for (int k = 0; k < obstacles.size();k++)
    {
        obSet.emplace(obstacles[k][0]*60001 + obstacles[k][1]);
    }
    // 自定义四个方向
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; // 0:北，1东，2南，3西
    int idx = 0; // 下标来控制方向
    // 当前坐标
    int x = 0;
    int y = 0;
    // 最大距离
    int ans = 0;
    for (int i = 0; i < commands.size();i++)
    {
        int curr = commands[i];
        if(curr == -1){
            idx = (idx + 1) % 4;
        }else if(curr == -2){
            idx = (idx + 3) % 4;
        }else
        {
            for (int k = 0; k < curr; k++)
            {
                // 碰到障碍停止行走
                if(obSet.count((x+dir[idx][0]) * 60001 + y+dir[idx][1])>0){
                    break;
                }
                x = x + dir[idx][0];
                y = y + dir[idx][1];
                // 需要次次计算距离取最大
                ans = max(ans, x * x + y * y);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    int ans = robotSim(commands, obstacles);
    cout << ans;
    return 0;
}
