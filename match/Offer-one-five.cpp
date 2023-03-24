// 剑指 Offer 15. 二进制中1的个数

// 解题思路：
// 直接循环检查给定整数 nnn 的二进制位的每一位是否为 1
// 具体代码中，当检查第 iii 位时，我们可以让 n 与 2^i
// 进行与运算，当且仅当 n 的第 i 位为 1 时，运算结果不为 0。

#include<iostream>

using namespace std;


int hammingWeight(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            ret++;
        }
    }
    return ret;
}

// n & (n−1)，其预算结果恰为把 n 的二进制位中的最低位的 1 变为 0 之后的结果。
// 如：6 & (6−1)=4, 6=(110)_2,4=(100)_2
//  ，运算结果 4 即为把 6 的二进制位中的最低位的 1 变为 0 之后的结果。

// 这样我们可以利用这个位运算的性质加速我们的检查过程，在实际代码中，我们不断让当前的 n 与 n−1 做与运算，直到 n 变为 0 即可。因为每次运算会使得 n 的最低位的 1 被翻转，
// 因此运算次数就等于 n 的二进制位中 1 的个数。

int hammingWeight1(uint32_t n) {
    int ret = 0;
    while (n) {
        n &= n - 1;
        ret++;
    }
    return ret;
}

//正常思路
int hammingWeight2(uint32_t n) {
    int res = 0;
    while (n != 0) {
        res += n % 2;
        n /= 2;
    }
    return res;
}
