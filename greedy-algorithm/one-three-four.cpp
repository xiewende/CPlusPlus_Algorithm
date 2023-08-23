// 134. 加油站

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

// 超出时间限制
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int sumG = accumulate(gas.begin(), gas.end(), 0);
    int sumC = accumulate(cost.begin(), cost.end(), 0);
    if(sumG < sumC){
        return -1;
    }
    
    vector<int> dis(n);
    for (int i = 0; i < n;i++)
    {
        dis[i] = gas[i] - cost[i];  
    }
    int idx;
    for (int i = 0; i < n;i++)
    {
        if(dis[i]<0){
            continue;
        }
        int curr = dis[i];
        int count = 1;
        idx = (i + 1) % n;
        while(count<n){
            curr += dis[idx];
            idx = (idx + 1) % n;
            count++;
            if(curr<0){
                break;
            }
        }
        if(count == n && curr>=0){
            return i;
        }
    }
    return -1;
}

int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    vector<int> dis(n);
    for (int i = 0; i < n;i++)
    {
        dis[i] = gas[i] - cost[i];  
    }
    int curr = 0;
    int i = 0;
    while(i<n){
        int count = 0;
        int currSum = 0;
        while(count<n){
            int j = (i + count) % n;
            currSum += dis[j];
            if(currSum<0){
                break;
            }
            count++;
        }
        if(count == n){
            return i;
        }else{
            i = i + count + 1; // 跳跃检索
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> gas = {5,8,2,8};
    vector<int> cost = {6,5,6,6};
    int ans = canCompleteCircuit1(gas, cost);
    cout << ans;
    return 0;
}
