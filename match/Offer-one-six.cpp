// 剑指 Offer 16. 数值的整数次方

#include<iostream>
// #include<cmatch>

using namespace std;

// 一个一个计算就是会超出时间限制
double myPow(double x, int n) {
    if(x==1.){
        return x;
    }
    int length = abs(n);
    double ans = 1;
    while(length){
        ans = ans * x;
        length--;
    }
    return n > 0 ? ans : 1 / ans;
}

// 递归+快速幂
// 求 x^64 = x -> x^2 -> x^4 -> x^8 -> x^16 -> x^32 -> x^64 
// 不需要一个一个乘以x，可以直接求中间的结果再来平方就可以得到。
// 这就是递归的思想
// 有的次幂未必可以被2整除的，这时候是需要多乘以一个 x


double quickMul(double x, int n){
    if(n==0){
        return 1.0;
    }
    double y = quickMul(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
}

double myPow1(double x, int n) {
    int length = abs(n);
    return n >= 0 ? quickMul(x, length) : 1.0 / quickMul(x, length);
}


int main(){
    double x = 2.00000;
    int n = -2;
    double ans = myPow(x, n);
    cout << ans;
    return 0;
}