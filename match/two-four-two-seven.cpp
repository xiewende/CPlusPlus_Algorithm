// 2427. 公因子的数目

//枚举

#include<iostream>
using namespace std;

int commonFactors(int a, int b) {
    int min_x = min(a, b);
    int ans = 0;
    for (int i = 1; i <= min_x; i++)
    {
        if(a % i == 0 && b % i == 0){
            ans++;
        }
    }
    return ans;
}

int main(){
    int a = 12;
    int b = 6;
    int ans = commonFactors(a, b);
    cout << ans;
    return 0;
}