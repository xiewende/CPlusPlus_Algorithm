// 452. 用最少数量的箭引爆气球

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 方法1，按照起点和终点小到大排序后，计算交集的个数个数即可
int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end());

    // 第一个区间
    int start = points[0][0];
    int end = points[0][1];

    int ans = 0;

    for (int i = 1; i < n; i++)
    {   
        // 另外区间
        if(points[i][0] > end){
            start = points[i][0];
            end = points[i][1];
            ans++;
        }else{
            // 有交集，更新交集
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
        }
    }

    return ans + 1;
}

// 类似贪心，
// 方法2，按照优先end的位置升序排序，若相同，则按照start升序，每次定义射箭的位置是 end ，依次来判断此时这支箭后续的气球中最多可以射多少气球
static bool cmp(vector<int>& a, vector<int>& b){
    if(a[1]==b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
int findMinArrowShots1(vector<vector<int>>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), cmp);
    int position = points[0][1];
    int ans = 0;
    for (int i = 1; i < n;i++)
    {
        // 这只箭不能射穿此个气球
        if(points[i][0] > position){
            position = points[i][1];
            ans++;
        }
    }
    return ans+1;
}

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> points = {{10,16}, {2,8}, {1,8}, {7,12}};
    int ans = findMinArrowShots1(points);
    cout << ans;
    return 0;
}
