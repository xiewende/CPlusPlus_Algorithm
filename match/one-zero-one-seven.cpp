// 1017. 负二进制转换

#include<iostream>
#include<string>

using namespace std;

// 按照规则来一步一步计算就好
string baseNeg2(int n) {
    if(n == 0){
        return "0";
    }
    string ans = "";
    int zhi = -2;
    int yu = 0;
    while(n != 0){
        yu = n % zhi;
        n = n / zhi;
        if(yu < 0){
            n = n - yu;
            yu = 0 - yu;
        }
        ans = to_string(yu) + ans;
    }
    return ans;
}


int main(){
    int a = 5;
    int b = -2;
    cout << a / b;
    cout << a % b << endl;
    int n = 6;
    string ans = baseNeg2(n);
    cout << ans;
    return 0;
}