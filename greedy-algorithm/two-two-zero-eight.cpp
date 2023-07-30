// 2208. 将数组和减半的最少操作次数

// 解题思路：优先队列 + 贪心算法

#include<iostream>
#include<vector>
#include<queue>
#include<numeric> // accumulate求和

using namespace std;

int halveArray(vector<int>& nums) {
    // 先计算数组的和
    double sum = accumulate(nums.begin(), nums.end(), 0.0); // 库函数求和
    double half = sum / 2.0;
    // priority_queue <int, vector<int>, less<int> > p;　　  　// 数组从大到小排序
    // priority_queue <int, vector<int>, greater<int> > q;　　// 从小到大排序
    priority_queue<double, vector<double>, less<int>> q;
    for(auto curr:nums){
        q.push(curr);
    }
    // 减半操作的次数
    int ans = 0;
    // 减半操作的和
    double reducedSum = 0;
    // 
    while(reducedSum < half){
        // 退出当前队列最大值
        double curr = q.top();
        q.pop();
        // 减半操作
        double halfCurr = curr / 2.0;
        reducedSum += halfCurr;
        // 队列重新加入
        q.push(halfCurr);
        // 一进一出属于完成1次
        ans += 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {32,98,23,14,67,40,26,9,96,96,91,76,4,40,42,2,31,13,16,37,62,2,27,25,100,94,14,3,48,56,64,59,33,10,74,47,73,72,89,69,15,79,22,18,53,62,20,9,76,64};
    int ans = halveArray(nums);
    cout << ans;
    return 0;
}

