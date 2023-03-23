// 剑指 Offer 14- II. 剪绳子 II

// 就是剪绳子的大数解决方案

// 当 n>4 的时候，必须剪一刀才可能得到最佳，
// 最优段长就是不可以剪的长度得到最优长 1 2 3就是，随便剪一刀得到长 x,y 是不可能得到 xy > x+y 的，其中 x+y = 1(2,3)
// 通过数学的方法证明。最优段长为3，也就是大于等于4的时候，尽可能每次都是剪成长为3的绳子，类似贪心下去就可以得到答案，
// 防止数值太大溢出，每次计算的时候都是根据题目取余

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int cuttingRope(int n) {
    if (n <= 3) return n - 1;
    long ret = 1;
    if (n % 3 == 1){
        ret = 4;
        n = n - 4;
    }
    if (n % 3 == 2){
        ret = 2;
        n = n - 2;
    }
    while (n) {
        ret = ret * 3 % 1000000007;            
        n = n - 3;
    }
    return (int)ret;
}

int main(){
    int ans = cuttingRope(8);
    cout << ans;
    return 0;
}