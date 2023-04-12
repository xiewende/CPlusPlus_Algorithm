// 1041. 困于环中的机器人

// 解题思路 模拟

// 1、若执行完一遍指令后，回到原点，不管其此时指向哪个方向，都可以形成环路
// 2、若执行完一遍指令后，没有回到原点
//     1）此时方向指向北，那就不会形成环路，只能一路向北
//     2）此时方向指向南，那接下来执行一遍指令就会回到原点
//     3）此时指向东，那就是右转了90°，若再执行一遍再右转得到指向南，若再执行一遍再右转得到指向西，若再执行一遍再右转得到指向北，回到原点 （1 ，3遍是相反的，2，4遍是相反的）
//     4）此时指向西，（类似指向东一样分析）
// 3、执行一次指令后，没有回到原点 并且 此刻指向北 才不可能形成环路

// 换句话说，如果执行了 4 次指令，还没有回到原点，则说明不可能存在环路了

#include<iostream>
#include<vector>
#include<utility>
#include<string>

using namespace std;

// 执行一次指令根据此刻指向方向来判断
bool isRobotBounded(string instructions) {
    vector<pair<int,int>> dirs = {{0,1}, {1,0},{0,-1},{-1,0}}; // 北 -》东 -》 南 -》 西  顺时针方向
    int length = instructions.length();
    int dirIndex = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < length; i++)
    {
        if(instructions[i] == 'G'){
            x = x + dirs[dirIndex].first;
            y = y + dirs[dirIndex].second;
        }else if (instructions[i] == 'L')
        {
            dirIndex = dirIndex + 3;
            dirIndex = dirIndex % 4;
        }else{
            dirIndex = dirIndex + 1;
            dirIndex = dirIndex % 4;
        }
    }
    return (x == 0 & y == 0) || dirIndex != 0;
}

// 执行4次指令来判断是否回到原点
bool isRobotBounded1(string instructions) {
    vector<pair<int,int>> dirs = {{0,1}, {1,0},{0,-1},{-1,0}}; // 北 -》东 -》 南 -》 西  顺时针方向
    int length = instructions.length();
    int dirIndex = 0;
    int x = 0;
    int y = 0;
    for (int j = 0; j < 4;j++)
    {
        for (int i = 0; i < length; i++)
        {
            if(instructions[i] == 'G'){
                x = x + dirs[dirIndex].first;
                y = y + dirs[dirIndex].second;
            }else if (instructions[i] == 'L')
            {
                dirIndex = dirIndex + 3;
                dirIndex = dirIndex % 4;
            }else{
                dirIndex = dirIndex + 1;
                dirIndex = dirIndex % 4;
            }
        }
    }
    
    return x == 0 && y == 0;
}


int main(){
    string instructions = "GGLLGG";
    bool ans = isRobotBounded1(instructions);
    cout << ans;
    return 0;
}