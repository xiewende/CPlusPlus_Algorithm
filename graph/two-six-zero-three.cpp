// 2603. 收集树中金币
// 拓扑排序
// 一个感性的类比，感觉像是摘一串葡萄，先把最外面没有果子的藤给摘了，然后在摘一圈尾巴，再摘一圈尾巴，最后计算。

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    vector<vector<int>> g(n); // 构建tu
    vector<int> indeg(n); //入读

    for(auto e: edges){
        int x = e[0];
        int y = e[1];
        g[x].push_back(y);
        g[y].push_back(x); // 建图
        indeg[x]++;
        indeg[y]++; //统计度数
    }

    int remain_edge = n - 1; //剩余边的数目

    //拓扑排序，去掉没有金币的子树
    queue<int> q;
    for (int i = 0; i < n;i++)
    {
        if(indeg[i] == 1 && coins[i]==0){ // 没有金币的叶子字节，度数为1且值为0
            q.push(i);
        }
    }

    while(!q.empty()){
        // 删除节点，就是边数减少1
        remain_edge--;
        int x = q.front();
        q.pop();
        for(auto next : g[x]){
            indeg[next]--;
            if(indeg[next]==1 && coins[next]==0){ // 删除了没有金币的叶子节点，上面还可以是没有金币的节点，继续删除没有金币的叶子字节，度数为1且值为0
                q.push(next);
            }
        }
    }

    // 再次拓扑排序

    for (int i = 0; i < n;i++)
    {
        if(indeg[i] == 1 && coins[i]){ //有金币的叶子节点（coins[i]==1 是避免把没有金币的叶子也加进来）
            q.push(i);
        }
    }
    // remain_edge -= q.size();
    while(!q.empty()){
        remain_edge--;
        int x = q.front();
        q.pop();
        for(auto next : g[x]){
            indeg[next]--;
            if(indeg[next]==1){
                q.push(next);
            }
        }
    }

    return max(remain_edge * 2, 0);
}