// 剑指 Offer 17. 打印从1到最大的n位数

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int> printNumbers(int n) {
    int length = pow(10, n) - 1;
    vector<int> ans(length, 0);
    for (int i = 0; i < length;i++)
    {
        ans[i] = i + 1;
    }
    return ans;
}

int main(){
    int n = 1;
    vector<int> ans = printNumbers(n);

    for(auto an : ans){
        cout << an;
    }
    return 0;
}