// 剑指 Offer II 109. 开密码锁

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<algorithm>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    if(target == "0000") {
        return 0;
    }
    if(find(deadends.begin(), deadends.end(), "0000") != deadends.end()){
        return -1;
    }
    queue<string> myqueue;
    myqueue.push("0000");
    unordered_set<string> visited;
    visited.emplace("0000");
    int ans = -1;
    string tem;
    while(!myqueue.empty()){
        int size = myqueue.size();
        ans++;
        for (int i = 0; i < size;i++)
        {
            string curr = myqueue.front();
            myqueue.pop();
            if(curr == target){
                return ans;
            }
            //遍历四个位置的改变
            for (int j = 0; j < 4;j++)
            {
                tem = curr;
                int one = curr[j] - '0';
                int one1 = (one + 1) % 10;
                int one2 = (one + 10 - 1) % 10;
                tem[j] = one1 + '0';
                if(!visited.count(tem) && find(deadends.begin(), deadends.end(), tem) == deadends.end() ){
                    myqueue.push(tem);
                    visited.emplace(tem);
                }
                tem[j] = one2 + '0';
                if(!visited.count(tem) && find(deadends.begin(), deadends.end(), tem) == deadends.end()){
                    myqueue.push(tem);
                    visited.emplace(tem);
                }
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    int ans = openLock(deadends, target);
    cout << ans;
    return 0;
}
