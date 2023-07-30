// 2178. 拆分成最多数目的正偶数之和

// dfs

#include<iostream>
#include<vector>

using namespace std;

bool dfs(vector<long long>& ans, long long finalSum, long long begin){
    // 已找到全部退出
    if(finalSum == 0){
        return true;
    }
    for (long long i = begin; i<=finalSum/2; i++)
    {
        if(finalSum-2*i < 0){
            break;
        }
        finalSum -= 2 * i;
        ans.emplace_back(2*i);
        bool flag = dfs(ans, finalSum, i+1);
        if(flag){
            return true;
        }
        finalSum += 2 * i;
        ans.pop_back();
    }
    return false;
}

vector<long long> maximumEvenSplit(long long finalSum) {
    // 奇数不可能满足情况
    if(finalSum % 2 != 0){
        return {};
    }
    // 构建答案
    vector<long long> ans;
    long long begin = 1;
    dfs(ans, finalSum, begin);
    return ans;
}

// 贪心算法，
// 从最小的偶整数 2 开始依次尝试拆分，直到剩余的数值小于等于当前被拆分的最大偶整数为止。
// 此时，我们已经拆分成尽可能多的偶数，不可能拆分出更多的互不相同的偶数。如果此时拆分后剩余的 finalSum 大于零，则将这个数值加到最大的偶整数上，从而保证所有的数互不相同。

vector<long long> maximumEvenSplit1(long long finalSum) {
    vector<long long> res;
    if (finalSum % 2 > 0) {
        return res;
    }
    for (int i = 2; i <= finalSum; i += 2) {
        res.push_back(i);
        finalSum -= i;
    }
    res.back() += finalSum;
    return res;
}


int main(int argc, char const *argv[])
{
    long long finalSum = 28;
    vector<long long> ans = maximumEvenSplit1(finalSum);
    for(auto curr : ans){
        cout << curr << " ";
    }
    return 0;
}
