// 1094.拼车

// 差分数组

#include<iostream>
#include<vector>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001, 0); // 差分数组
    for(auto num : trips){
        diff[num[1]] += num[0];
        diff[num[2]] -= num[0];
    }
    if(diff[0]>capacity){
        return false;
    }
    for(int i=1;i<1001;i++){
        diff[i] = diff[i-1] + diff[i];
        if(diff[i]>capacity){
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> trips = {{9, 0, 1}, {3,3,7}};
    int capacity = 4;
    bool ans = carPooling(trips, capacity);
    cout << ans;
    return 0;
}
