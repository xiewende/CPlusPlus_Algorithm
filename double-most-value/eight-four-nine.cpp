// 849. 到最近的人的最大距离

#include<iostream>
#include<vector>

using namespace std;

bool judge(vector<int>& seats, int dis){
    int firstIdx = 0;
    for (int i = 0; i < seats.size(); i++)
    {
        if(seats[i] == 1){
            firstIdx = i;
            if(i>=dis){
                return true;
            }else{
                break;
            }
        }
    }
    for (int i = seats.size()-1; i >= 0; i--)
    {
        if(seats[i] == 1){
            if((seats.size()-i-1)>=dis){
                return true;
            }else{
                break;
            }
        }
    }

    // int last = 0;
    for (int i = firstIdx+1; i < seats.size(); i++)
    {
        if(seats[i] == 1){
            if((i-firstIdx)/2 >= dis){
                return true;
            }
            firstIdx = i;
        }
    }
    return false;
}

int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    // int ans = n / 2;
    int left = 0;
    int right = n;
    int ans = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(judge(seats, mid)){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}

int maxDistToClosest1(vector<int>& seats) {
    int n = seats.size();
    // int ans = n / 2;
    int firstIdx = 0;
    int ans = 0;
    for (int i = 0; i < seats.size(); i++)
    {
        if(seats[i] == 1){
            firstIdx = i;
            ans = i;
            break;
        }
    }
    
    for (int i = firstIdx+1; i < seats.size(); i++)
    {
        if(seats[i] == 1){
            ans = max(ans, (i-firstIdx)/2);
            firstIdx = i;
        }
    }
    ans = max(ans, n - firstIdx - 1);
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<int> seats = {1,0,0,0,1,0,1};
    int ans = maxDistToClosest1(seats);
    cout << ans;
    return 0;
}

