//  84. 柱状图中最大的矩形

// 解题思路：栈：底小顶大

// 遍历数组，依次入栈，保持栈底小，栈顶大，递增栈，存储的都是数组下标，方便操作

// 遇到 nums[i] < nums[stack.top()], 当前元素大于栈顶元素，也就是说明栈顶元素往右延申失败，到这里就是需要计算矩形的大小，
// 此时矩形的 height = nums【stack.top()】，weight = i - stack.top() - 1, 计算依次答案，取答案大的，
// 然后栈顶元素出栈，继续比较 nums[i]和 nums[stack.top()] 的，while来控制。
// 比较晚，nums[i]需要入栈。

// 遍历完毕后，若栈不为空，里面肯定就是递增数组，
// 此时，height = nums[stack.top], weight = n-stack.top()-1, 取n是因为肯定可以向右延申到边界，

// 注意：若栈为空，左边界就是 -1；

// 例子 ： 2,1,5,6,2,3


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
            int idx = s.empty() ? -1 : s.top(); // 栈顶元素的前一个元素的下标
            int weight = i - idx - 1; // 卡在中间，例如 【0 3 2 5】 计算高度为2的时候，左index是0这个位置，而不是自身
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
