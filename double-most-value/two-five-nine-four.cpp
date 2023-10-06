#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

// 二分查找，最最值问题

using namespace std;

// 判断是否满足
bool judge(vector<int>& ranks, long long min, int cars){
    int count = 0;
    for (int i = ranks.size() - 1; i >= 0;i--)
    {
        // long long rank = (long long)(ranks(i));
        long long curr = min / ranks[i];
        count += sqrt(curr);
    }
    return count >= cars;
}

long long repairCars(vector<int>& ranks, int cars) {
    int maxV = *max_element(ranks.begin(), ranks.end());
    int minV = *min_element(ranks.begin(), ranks.end());

    long long high = cars * cars * maxV; // 可能满足的最大值
    long long low = 0; // 满足的最小值
    long long ans;
    // sort(ranks.begin(), ranks.end());
    // 二分查找判断值是否满足
    while (low<=high)
    {
        long long mid = (low + high) / 2;
        // 若满足，缩小搜索范围
        if(judge(ranks,mid,cars)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    long long ans = repairCars(ranks, cars);
    cout << ans;
    return 0;
}
