// 2731. 移动机器人

// 解题思路：
// 1、数组的两两做差，打乱数组的顺序不会影响最终的结果
// 2、碰撞相反方向，可以看成是直接将机器人换位，相互的机器还是按照原来的方向行驶

// 根据2，我们可以直接算法每个机器走d步后在哪个坐标，
// 然后计算最终位置的两两差，
// 方便计算最终位置的两两差，利用性质1，先对数组进行排序，得到小到大的数组
// 从小枚举 a[i] ，此时左边有 i 个数都不超过 a[i] 那么 a[i] 与其左侧的机器人的距离之和为：
// (a[i]-a[0]) + (a[i]-a[1]) + (a[i]-a[2]) +..+ (a[i]-a[i-1])
// = i*a[i] - (a[0]+a[1]+a[2]+..+a[i-1])
// 所以可以利用前缀和 sum[i] 可以一次遍历得到最终的两两差


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int sumDistance(vector<int>& nums, string s, int d) {
    int n = nums.size();
    const int MOD = 1e9 + 7;
    vector<long long> a(n);
    for (int i = 0; i < n;i++)
    {
        a[i] = s[i] == 'L' ? nums[i] - d : nums[i] + d;
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n;i++)
    {
        ans = (ans + i * a[i] - sum) % MOD;
        sum += a[i];
    }
    return ans;
}