// 1782. 统计点对的数目

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
    vector<int> outNode(n + 1, 0); // 记录出度
    vector<vector<int>> con(n + 1, vector<int>(n + 1, 0)); //记录 i j节点有多少条边

    for (int i = 0; i < edges.size();i++)
    {
        outNode[edges[i][0]]++;
        outNode[edges[i][1]]++;
        con[edges[i][0]][edges[i][1]]++;
        con[edges[i][1]][edges[i][0]]++;
    }

    int len = (n * (n - 1)) / 2;
    vector<int> dis(len+1);
    int index = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = i + 1; j <= n;j++)
        {
            int curr = outNode[i] + outNode[j] - con[i][j];
            dis[index++] = curr;
        }
    }
    sort(dis.begin(), dis.end());
    
    // 构造答案
    int m = queries.size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m;i++)
    {
        int curr = 0;
        int idx = dis.size() - 1;
        while(dis[idx] > queries[i]){
            curr++;
            idx--;
        }
        ans[i] = curr;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n = 5;
    vector<vector<int>> edges = {{1,5}, {1,5}, {3,4}, {2,5}, {1,3}, {5,1}, {2,3}, {2,5}};
    vector<int> queries = {1,2, 3,4,5};
    vector<int> ans = countPairs(n, edges, queries);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}
