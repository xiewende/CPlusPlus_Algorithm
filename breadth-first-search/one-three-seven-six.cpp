// 1376. 通知所有员工所需的时间

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<utility>

using namespace std;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    // 创建 管理者和其下属的关系，key:管理者，value：下属们
    unordered_map<int, vector<int>> managers;
    for (int i = 0; i < n; i++)
    {
        managers[manager[i]].emplace_back(i);  //最底层的员工不会记录在这里
    }

    //创建队列，第一个值表示该员工，第二个值表示信息到该员工的时间耗费
    queue<pair<int, int>> myqueue;
    myqueue.push({headID, 0});

    int ans = 0;
    while(!myqueue.empty()){
        auto curr = myqueue.front();
        myqueue.pop();
        // 如果该员工是否是最底层的员工
        if(!managers.count(curr.first)){
            ans = max(ans, curr.second);  //最后一个员工，取其得到消息的时间
        }else{
            // 不是最后一个员工
            for(auto next : managers[curr.first]){
                myqueue.push({next, curr.second + informTime[curr.first]}); // 下一个员工收到信息的时间
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = 8;
    int headID = 0;
    vector<int> manager = {-1,5,0,6,7,0,0,0};
    vector<int> informTime = {89,0,0,0,0,523,241,519};
    int ans = numOfMinutes(n, headID, manager, informTime);
    cout << ans;
    return 0;
}

