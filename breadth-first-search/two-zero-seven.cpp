
// 207. 课程表

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    // 纪录prerequisites
    unordered_map<int ,vector<int>> pres; // key:当前课程，val:下一课程
    // 记录每个点的入度
    vector<int> inNode(numCourses);
    for (int i = 0; i < n;i++)
    {
        pres[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        inNode[prerequisites[i][1]]++;
    }
    // 队列来判断
    queue<int> q;
    // 入度为0的先入队
    for (int i = 0; i < numCourses;i++)
    {
        if(inNode[i] == 0){
            q.push(i);
        }
    }
    // 开始遍历
    int count = 0;
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        count++;
        for(auto next : pres[currNode]){
            // 下一个节点的全部入度减一
            inNode[next]--;
            // 入度为0可以入队
            if(inNode[next]==0){
                q.push(next);
            }
        }
    }
    return count == numCourses;
}   

int main(int argc, char const *argv[])
{
    vector<vector<int>> prerequisites = {{1,0}, {0,1}};
    int numCourse = 2;
    bool ans = canFinish(numCourse, prerequisites);
    cout << ans;
    return 0;
}

