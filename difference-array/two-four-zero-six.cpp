// 2406. 将区间分为最少组数

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

// 贪心：每次判断当前区间是否可以和已存在组的最小右边界划分为一个组，
// 排序+小根堆
// 按照开始时间进行排序
// 小根堆，存放的最早的结束的区间右边界
// 若新来的左边界大于堆顶元素，说明此时可以把这个新来的和原来堆顶的划分一个组，此时把堆顶元素去掉，载入新的有边界
// 若新来的左边界小于或等堆顶元素，则说明新来的不可以和任何之前一个组，只能自己存在一个组。此时，直接将这个组的右边界添加到小顶堆中
int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> q;
    for(auto curr : intervals){
        if(!q.empty() && curr[0]>q.top()){
            q.pop();
        }
        q.push(curr[1]);
    }
    return q.size();
}

// 差分数组
// 题目看成区间上下车的模型，在left上车，在right下车，
// 只需要判断同时在车上的最大人数就是最少的组数
// 利用map来实现
int minGroups1(vector<vector<int>>& intervals) {
    map<int, int> m;
    for(auto curr:intervals){
        int l = curr[0];
        int r = curr[1] + 1;
        m[l]++;
        m[r]--;
    }

    int ans = 0;
    int sum = 0;
    for (auto i = m.begin(); i != m.end(); ++i) {
        sum += i->second;
        ans = max(ans, sum);
    }
    return ans;
}




