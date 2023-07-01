// 2485. 找出中枢整数

#include<iostream>
#include<vector>

using namespace std;

int pivotInteger(int n) {
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n;i++)
    {
        sum[i] = sum[i - 1] + i;
    }

    for (int i = 1; i <= n;i++)
    {
        if(sum[i] == sum[n]-sum[i-1]){
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int n = 4;
    int ans = pivotInteger(n);
    cout << ans;
    return 0;
}
