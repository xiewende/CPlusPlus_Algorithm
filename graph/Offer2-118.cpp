// 剑指 Offer II 118. 多余的边

// 解题思路：并查集

// 无向图连通性 考虑 并查集 ;有向图依赖性 考虑 深度广度优先 拓扑排序

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

int find_parent(vector<int>& parent, int node){
    // 只有根节点是 idx 和 parent[idx]是相等的

    // 1、循环找根节点
    // while(parent[node] != node){
    //     node = parent[node];
    // }
    // return node;

    // 递归找根节点 路径会优化
    if(parent[node] != node){
        parent[node] = find_parent(parent, parent[node]);
    }
    return parent[node];
}

void union_nodes(vector<int>& parent, int node1, int node2){
    int node1_parent = find_parent(parent, node1);
    int node2_parent = find_parent(parent, node2);

    //将节点1的根节点 指向 节点2的根节点
    parent[node1_parent] = node2_parent;
    // 反过来也可以的
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    // index：当前节点，value：当前节点的根节点
    // 一开始每个节点的根节点都是自身，
    vector<int> parent(n+1, 0);
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        // 判断两个节点的根节点是否相同，相同则属于同一个连通区域，也就是若添加当前边会有环形成，若不同，则需要合并这两个不一样的连通分量
        if(find_parent(parent, node1) != find_parent(parent, node2)){
            // 两个节点不属于同一个连通分量，合并这两个联通分量
            union_nodes(parent, node1, node2);
        }else{
            // 两个节点的父节点相同，则是属于同一个连通分量。添加当前边就会成为环，则返回该边即可
            return edges[i];
        }
    }
    return {};
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> ans = findRedundantConnection(edges);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}
