// 1615. 最大网络秩
// 图的度的概念 
// 解题思路： 枚举暴力
// 先求每个节点的度是多少，同时需要判断两个节点是否有道路连接
// degree[i] : i 节点的度， connect[i][j] : 节点i和节点j是否有连接 有1，无0


// 最大网络秩 = degree[i] + degree[j] - connect[i][j] ( 排除重复计算)


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>> connect(n, vector<int>(n, 0));
    vector<int> degree(n, 0);
    for(auto road : roads){
        // 求度
        degree[road[0]]++;
        degree[road[1]]++;
        // 判断是否有相连
        connect[road[0]][road[1]] = 1;
        connect[road[1]][road[0]] = 1;
    }

    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            int zhi = degree[i] + degree[j] - connect[i][j];
            ans = max(ans, zhi);
        }
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3},{2,3},{2,4}};
    int ans = maximalNetworkRank(n, roads);
    cout << ans;
    return 0;
}
