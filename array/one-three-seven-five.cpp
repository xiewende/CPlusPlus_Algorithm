// 1375. 二进制字符串前缀一致的次数

// 1、暴力，超时
// 2、巧劲：在第 i 次翻转之后，我们希望 [1,i] 内的所有位都是 1，这等价于「前 i 次翻转中下标的最大值等于 i」。

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool check(vector<int>& str, int index){
    for (int i = 0; i <= index;i++)
    {
        if(str[i] != 1){
            return false;
        }
    }
    return true;
}

int numTimesAllBlue(vector<int>& flips) {
    int n = flips.size();
    vector<int> str(n, 0);
    int ans = 0;
    for(int i = 1; i <= n;i++)
    {
        int index = flips[i - 1]-1;
        str[index] = 1;
        if(check(str, i-1)){
            ans++;
        }
    }
    return ans;
}   

int numTimesAllBlue1(vector<int>& flips) {
    int n = flips.size();
    int ans = 0;
    int right = 0;
    for(int i = 0; i < n;i++)
    {
        right = max(right, flips[i]);
        if(right == i+1){
            ans++;
        }
    }
    return ans;
}   


int main(int argc, char const *argv[])
{
    vector<int> flips(4,0);
    for (int i = 0; i < 4;i++)
    {
        cin >> flips[i];
    }
    int ans = numTimesAllBlue(flips);
    cout << ans;
    return 0;
}
