
// 210. 课程表2

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    // 纪录prerequisites
    unordered_map<int ,vector<int>> pres; // key:当前课程，val:下一课程
    // 记录每个点的入度
    vector<int> inNode(numCourses);
    for (int i = 0; i < n;i++)
    {
        pres[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        inNode[prerequisites[i][0]]++;
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
    vector<int> ans;
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        // count++;
        ans.emplace_back(currNode);
        for(auto next : pres[currNode]){
            // 下一个节点的全部入度减一
            inNode[next]--;
            // 入度为0可以入队
            if(inNode[next]==0){
                q.push(next);
            }
        }
    }
    if(ans.size()==numCourses){
        return ans;
    }else{
        return {};
    }
    // return  ? ans : {};
}   

int main(int argc, char const *argv[])
{
    vector<vector<int>> prerequisites = {{1,0},{2,0}, {3,1}, {3,2}};
    int numCourse = 4;
    vector<int> ans = findOrder(numCourse, prerequisites);
    for(auto curr : ans){
        cout << curr << " ";
    }
    // cout << ans
    return 0;
}

