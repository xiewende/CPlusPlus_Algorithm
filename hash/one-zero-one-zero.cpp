// 1010. 总持续时间可被 60 整除的歌曲

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int, int> visited;
    int len = time.size();
    visited[time[0]%60]++;
    int ans = 0;
    for (int i = 1; i < len; i++)
    {
        int curr = (60 - time[i] % 60) % 60;
        if(visited.count(curr)>0){
            ans += visited[curr];
        }
        visited[time[i] % 60]++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    vector<int> times = {60,60,60};
    int ans = numPairsDivisibleBy60(times);
    cout << ans;
    return 0;
}
