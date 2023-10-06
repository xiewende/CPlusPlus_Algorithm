// LCR 035. 最小时间差

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


int toMin(string s){
    int hours = atoi(s.substr(0, 2).c_str());
    int mins = atoi(s.substr(3, 2).c_str());
    return hours * 60 + mins;
}

int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    
    unordered_set<int> seen;
    for (int i = 0; i < n; i++)
    {
        int min = toMin(timePoints[i]);
        if(seen.count(min)>0){
            return 0;
        }
        seen.emplace(min);
    }
    vector<int> times(seen.begin(), seen.end());
    sort(times.begin(), times.end());
    int ans = 1440;
    int n1 = times.size();
    for (int i = 1; i < n1;i++)
    {
        int dis1 = times[i] - times[i - 1];
        ans = min(ans, dis1);
    }
    ans = min(ans, 1440 - (times[n1 - 1] - times[0]));
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<string> timePoints = {"01:01","02:01"};
    int ans = findMinDifference(timePoints);
    cout << ans;
    return 0;
}
