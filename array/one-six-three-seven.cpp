// 1637. 两点之间不包含任何点的最宽垂直区域

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>>& points) {

    sort(points.begin(), points.end());
    int row = points.size();
    int ans = 0;
    for (int i = 1; i < row; i++)
    {
        ans = max(ans, points[i][0] - points[i - 1][0]);
    }
    return ans;
}

int main(){
    vector<vector<int>> points{{3, 1}, {9, 0}, {1, 0}, {1, 4},{5,3},{8,8}};
    int ans = maxWidthOfVerticalArea(points);
    cout << ans;
    return 0;
}