// 1015. 可被 K 整除的最小整数

#include<iostream>
#include<unordered_set>

using namespace std;

// 遍历，但是需要注意重复计算的值
int smallestRepunitDivByK(int k) {
    int redis = 1 % k;
    int len = 1;
    unordered_set<int> visited;
    visited.emplace(redis);
    while(redis != 0){
        redis = (redis * 10 + 1) % k;
        if(visited.count(redis)>0){
            return -1;
        }
        visited.emplace(redis);
        len++;
    }
    return len;
}

// 能够被 2 和 5 整除的数肯定不满足，否则必须满足
int smallestRepunitDivByK1(int k) {
    // 能够被2或者5整除的，则无解，返回-1
    if(k % 2==0 || k%5==0){
        return -1;
    }
    int redis = 1 % k;
    int len = 1;
    while(redis != 0){
        redis = (redis * 10 + 1) % k;
        len++;
    }
    return len;
}


int main(int argc, char const *argv[])
{
    int k = 7;
    int ans = smallestRepunitDivByK(k);
    cout << ans;
    return 0;
}
