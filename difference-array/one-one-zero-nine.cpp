// 1109.航班预订统计

// 差分数组

#include<iostream>
#include<vector>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n, 0); //差分数组
    for(auto num : bookings){
        int f = num[0] - 1;
        int l = num[1] - 1;
        int s = num[2];
        diff[f] += s;
        if(l+1<n){
            diff[l + 1] -= s;
        }
    }

    // 差分数组的前缀和就是原数组。
    for (int i = 1; i < n;i++)
    {
        diff[i] = diff[i - 1] + diff[i];
    }

    return diff;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> bookings = {{1,2,10}, {2,3,20}, {2,5,25}};
    int n = 5;
    vector<int> ans = corpFlightBookings(bookings, n);
    for(auto num:ans){
        cout << num << " ";
    }
    return 0;
}
