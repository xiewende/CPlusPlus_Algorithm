//  84. 柱状图中最大的矩形

#include<iostream>
#include<vector>
#include<stack>

using namespace std;


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s; // 高度值小到大, 但是存放的是数组下标
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && heights[i] < heights[s.top()]){
            int height = heights[s.top()];
            s.pop();
            int idx = s.empty() ? -1 : s.top();
            int weight = i - idx - 1;
            ans = max(ans, height*weight);
        }
        s.push(i);
    }
    //递增的情况
    while(!s.empty()){
        int height = heights[s.top()];
        s.pop();
        int indx = s.empty() ? -1 : s.top();
        int weight = n - indx - 1;
        ans = max(ans, height*weight);
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    vector<int> nums = {2,1,5,6,2,3};
    int ans = largestRectangleArea(nums);
    cout << ans;
    return 0;
}
