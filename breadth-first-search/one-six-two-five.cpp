// 1625. 执行操作后字典序最小的字符串

// 暴力解决，采用 BFS
// set 配合 queue 实现 BFS， 温故BFS的模板


#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<queue>

using namespace std;

string findLexSmallestString(string s, int a, int b) {

    //记录操作后的string是否出现过
    unordered_set<string> visit{s};
    // queue 来变出队边遍历
    queue<string> que{{s}};
    string ans = s; // 需要比较的答案
    int n = s.length();
    while(!que.empty()){
        string curr = que.front();
        que.pop();
        ans = min(ans, curr); // 取最小
        //第一种操作
        string t1 = curr;
        for (int i = 1; i < n; i += 2){
            t1[i] = (t1[i] - '0' + a) % 10 + '0';
        }
        //第二种操作
        string t2 = curr.substr(n - b) + curr.substr(0, n - b);
        // 判断是否出现遍历过
        for(auto t : {t1, t2}){
            if(!visit.count(t)){
                visit.insert(t);
                que.emplace(t);
            }
        }
    }

    return ans;
}

int main(){
    string s = "43987654";
    int a = 7;
    int b = 3;

    string ans = findLexSmallestString(s, a, b);

    cout << ans;

    return 0;
}