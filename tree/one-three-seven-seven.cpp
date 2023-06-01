// 1377. T 秒后青蛙的位置

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    if(edges.size()==0){
        return 1;
    }
    unordered_map<int, vector<int>> grap;
    for (int i = 0; i < edges.size();i++)
    {
        grap[edges[i][0]].push_back(edges[i][1]);
        grap[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q;
    q.push(1);
    unordered_map<int, double> pro;
    pro[1] = 1.;
    vector<bool> vis(n + 1, false);
    vis[1] = true;

    if(pro.count(target) > 0){
        int len = 0;
        vector<int> next = grap[target];
        // for(int j=0;j<next.size();j++){
        //     if(!vis[next[j]]){
        //         len++;
        //     }
        // }
        // if(len==0){
        //     return pro[target];
        // }
        // return t==0 ? pro[target] : 0;
        if(next.size()==0 || t==0){
            return pro[target];
        }else{
            return 0;
        }
    }

    while(!q.empty() && t>0){
        int q_size = q.size();
        for (int k = 0; k < q_size;k++)
        {
            int curr_node = q.front();
            q.pop();
            vector<int> curr_next = grap[curr_node];
            int size = curr_next.size();
            int fenmu = 0;
            for (int i = 0; i < size;i++)
            {
                if(!vis[curr_next[i]]){
                    fenmu++;
                }
            }
            for (int i = 0; i < size;i++)
            {
                if(!vis[curr_next[i]]){
                    vis[curr_next[i]] = true;
                    q.push(curr_next[i]);
                    pro[curr_next[i]] = (1. / fenmu) * pro[curr_node];
                    if(pro.count(target) > 0){
                        vector<int> next = grap[target];
                        int len = 0;
                        for(int j=0;j<next.size();j++){
                            if(!vis[next[j]]){
                                len++;
                            }
                        }
                        if(len==0){
                            return pro[target];
                        }
                        return t==1 ? pro[target] : 0;
                    }
                }
            }
        }
        t--;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{2,1}, {3,2},{4,3}, {5,3}, {6,5}, {7,3}, {8,4}, {9,5}};
    int n = 9;
    int t = 9;
    int target = 1;
    double ans = frogPosition(n, edges, t, target);
    cout << ans;
    return 0;
}


