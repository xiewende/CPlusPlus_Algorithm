// 1626. 无矛盾的最佳球队

// 解题思路：排序 + 动态规划  (需要对具体问题具体建模)
// 队员按照分数升序进行排序，分数相同时，则按照年龄升序进行排序
// 一个一个添加队员，分数是增加的，可以判断年龄来判断是不是矛盾的，
// 排序完就是年龄控制的最长子序列 (类似最长递增子序列)
// 最长递增子序列的详细解法看我博客

// 1、构造结构体或者能够存储上述两个信息的结构体 这里采用pair
//  peoper.firse = scores; peoper.firse = ages
//  按照 《分数升序进行排序，分数相同时，则按照年龄升序进行排序》规则排序真不队员对象， 就是pair的peoper
// 2、构造 dp[i]，定义为第 i 个队员时候的最大分数。
//  dp[i] = max(dp[i], dp[j]) + scores[i]  其中 dp[i] 是需要遍历的，0 <= i <= length ; 0 <= j <= i;

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

// cmap 传入的就是需要排序的对象，可以是结构体那种多个值的
// 多个值就按照多种策略排序，默认的是一个按照一个的次序来升序排序的
// 第一个值 《 第二个值就是升序，第一个值 》第二个值就是降序

// 在这里，实现的是先按照 a b 中的第一个值升序，若第一个值相等，按照第二个值升序排序
// 也可以包装成结构体来做
bool cmap(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }   //a b 的第一个值按照升序
    // 下面就是 a.first == b.first 的情况的了
    return a.second < b.second;
}

int bestTeamScore(vector<int>& scores, vector<int>& ages) {

    int length = scores.size();
    //队员按照分数升序进行排序，分数相同时，则按照年龄升序进行排序
    //构造结构体来排序
    vector<pair<int, int>> peopers(length); // pair中第一个值是分数，第二个值是年龄
    for (int i = 0; i < length; i++)
    {
        peopers[i] = {scores[i], ages[i]};
    }
    //对于规则对队员的分数和年龄整体排个序，没有cmap默认的就是升序排序
    sort(peopers.begin(), peopers.end(), cmap);

    // 接下来就是最长子序列问题
    vector<int> dp(length, 0);
    int ans = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(peopers[j].second <= peopers[i].second){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += peopers[i].first;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int> scores{4, 5, 6, 5};
    vector<int> ages{2, 1, 2, 3};
    int ans = bestTeamScore(scores, ages);
    cout << ans;
    return 0;
}