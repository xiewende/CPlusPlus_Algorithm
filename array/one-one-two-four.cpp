// 1124. 表现良好的最长时间段

// 给定 hours[n]数组， 定义 hour 大于 8 的为 1，小于 8 的为 -1 ，
// 定义 sum[i] 为 hours[i] 的前缀数组和
// sum[right] - sum[left] > 0 代表在 hours[left]..hours[right] 满足表现良好时间段，==》 sum[right] - sum[left] > 0
// 故求 left-right 的最大值

// 如果 sum[i]>0，那么 j=0j=0j=0 就是最远的左端点，因为 ssum[0]=0，故 sum[i]−sum[0]=s[i]>0，符合要求。
// 如果 sum[i]≤ 0 ，那么 j 就是 sum[i]−1 首次出现的位置。为什么是 sum[i] 而不是其它更小的数？
// 这是因为前缀和是从 0 开始的，由于 nums 中只有 1 和 −1，那么相邻前缀和的差都恰好为 1，要想算出比 sum[i] 更小的数，
// 必然会先算出 sum[i]，那么这些更小数必然在 sum[i]−1 首次出现的位置的右边。


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int longestWPI(vector<int>& hours) {

    unordered_map<int, int> visit{{0, -1}};

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < hours.size(); i++)
    {
        sum += hours[i] > 8 ? 1 : -1;

        if(sum>0){
            ans = max(ans, i + 1);
        }else{
            if(visit.count(sum-1)){
                ans = max(ans, i - visit[sum - 1]);
            }
        }

        if (!visit.count(sum)){
            visit[sum] = i;
        }
    }

    return ans;
}

int main(){
    vector<int> hour{9, 9, 6, 06, 6, 9};

    int ans = longestWPI(hour);

    cout << ans;
}