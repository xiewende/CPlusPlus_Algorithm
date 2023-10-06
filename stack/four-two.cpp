// 42.接雨水

// 经典题目

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// 动态规划
// 判断某个位置的垂直方向是否可以装的下水，
// 比如到达某个位置i，其高度是height[i]
// 左边比他高的且是最高的是left，右边比他高的且是最高的是right
// 此时，这个位置的垂直方向可以有 min(left, right)-height[i]的雨水
// 所以定义两个dp，分别存在左边和右边的的最大值,先遍历得到这两个dp的值，包括本省
// 然后遍历原数组，求得每个位置的水量即可
// height[i]处的雨水量是，min(dp_left[i], dp_right[i]) - height[i]，也有可能是0的时候。
int trap(vector<int>& height) {
    int n = height.size();
    //左往右看最大值
    vector<int> dp_right(n);
    dp_right[n-1] = height[n-1];
    //右往左看最大值
    vector<int> dp_left(n);
    dp_left[0] = height[0];

    for (int i = 1; i < n;i++)
    {
        dp_left[i] = max(dp_left[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0;i--){
        dp_right[i] = max(dp_right[i + 1], height[i]);
    }

    //统计答案
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        int min_h = min(dp_left[i], dp_right[i]);
        int curr = min_h - height[i];
        ans += curr;
    }

    return ans;
}

// 单调栈，单调递减栈
// 水平方向看是否可以有雨水来接
int trap1(vector<int>& height) {
    int n = height.size();
    stack<int> s; // 存储的是下标
    int idx = 0;
    int ans = 0;
    while (idx<n)
    {
        /* code */
        // 遍历判断是否有满足的情况
        while (!s.empty() && height[idx] > height[s.top()])
        {
            /* code */
            int top = s.top();
            s.pop();
            //左边没有值了，也就是左边比当前小的全没有了
            if(s.empty()){
                break;
            }

            // 左边的柱子,判断当前柱子和left柱子之间是否可以有可以存储水
            int left = s.top();
            // 
            int currWidth = idx - left - 1;
            int currHigh = min(height[left], height[idx]) - height[top];  // top就是单调栈中 顶部元素的前一个值。
            ans += currHigh * currWidth;
        }
        // 入栈
        s.push(idx);
        idx++;
    }
    return ans;
}

// 双指针
int trap(vector<int>& height) {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    vector<int> height = {4,2,0,3,2,5};
    int ans = trap(height);
    cout << ans;
    return 0;
}
