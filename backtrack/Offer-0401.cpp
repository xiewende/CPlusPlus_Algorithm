// 面试题 04.01. 节点间通路

// 解题思路：

// 1、直接BFS和DFS是超时的

// 2、1）先计算出每个节点的出度，也就是统计每个节点可以到达的节点
//    2）再利用 BFS 统计即可；或者再用 DFS 即可

// 牛逼做法，两次循环即可
 

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// 直接 dfs 超时
bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int start, int target){
    if(start == target){
        return true;
    }

    for (int i = 0; i < graph.size();i++)
    {
        if(visited[i] || graph[i][0] != start){
            continue;
        }

        visited[i] = true;
        bool ans = dfs(graph, visited, graph[i][1], target);
        if(ans){
            return ans;
        }
        visited[i] = false;
    }
    return false;
}

bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
    sort(graph.begin(), graph.end());
    for (int i = 0; i < graph.size();i++)
    {
        int first = graph[i][0];
        int second = graph[i][1];
        for (int j = i + 1; j < graph.size();){
            if((graph[j][0] == first && graph[j][1] == second) || (graph[j][1] == first && graph[j][0] == second)){
                graph.erase(graph.begin() + j);
            }else{
                break;
            }
        }
    }
    vector<bool> visited(graph.size(), false);
    return dfs(graph, visited, start, target);
}


// 先计算出每个节点的出度，也就是统计每个节点可以到达的节点
// 再利用 BFS 统计即可
// 需要注意双边和自环
bool findWhetherExistsPath1(int n, vector<vector<int>>& graph, int start, int target) {

    vector<bool> isVisited(n, 0); // 判断某个节点是否访问
    // 统计各个节点的出度
    unordered_map<int,vector<int>> root_out;
    for (int i = 0; i < graph.size();i++)
    {
        root_out[graph[i][0]].push_back(graph[i][1]);
    }
    queue<int> myqueue;
    myqueue.push(start);
    while(!myqueue.empty()){
        int curr = myqueue.front();
        myqueue.pop();
        if(curr == target){
            return true;
        }
        vector<int> next = root_out[curr];
        for (int i = 0; i < next.size();i++)
        {   
            if(!isVisited[next[i]]){ //没有访问过的
                isVisited[next[i]] = true;
                myqueue.push(next[i]);
            }
        }
    }
    return false;
}

// 牛逼
bool findWhetherExistsPath2(int n, vector<vector<int>>& graph, int start, int target) {
    //建立hash表，记录当下可以到达的结点，hash[i]为i是否可以到达
    vector<bool> hash(n);
    hash[start] = true;

    for(int i=0;i<graph.size();++i){
        //每当一条路径的初始位置可以到达，那么这条路径的终点就可以到达
        if(hash[graph[i][0]]){
            hash[graph[i][1]] = true;
        }
    }

    for(int i=graph.size()-1;i>=0;i--){
        //每当一条路径的初始位置可以到达，那么这条路径的终点就可以到达
        if(hash[graph[i][0]]){
            hash[graph[i][1]] = true;
        }
    }
    return hash[target];
}

int main(){
    vector<vector<int>> graph = {{0, 1}, {0, 1}, {0, 4}, {0, 4}, {0, 1}, {1, 3}, {1, 4}, {1, 3}, {2, 3}, {3, 2}};
    int start = 0;
    int target = 4;
    int n = 5;
    bool ans = findWhetherExistsPath2(n, graph, start, target);
    cout << ans;
    return ans;
}