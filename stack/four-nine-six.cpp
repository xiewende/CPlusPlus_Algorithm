// 496. 下一个更大元素 I

// 解题思路：单调栈的模板题目

// 单调栈：底大顶小

// 1、先记录nums2中每个元素的下一个比他大的元素；
    // 因为是下一次，我们需要倒序遍历nums2
    // 倒叙遍历nums2，当前值为 curr
    //     while curr >= 栈顶元素，则出栈，
    //     下一步判断
    //     栈是否为空：若为空则说明该元素curr是在其位置往后没有比其大的值了，此时 curr的下一个比他大值为-1
    //                 若不为空，则curr的下一个比他大的值是栈顶元素。
    //     curr 入栈

// 2、由于是找到 nums1中各个元素的下一个比自己大的数字，我们在第一步中记录 各个 curr 对应其的下一个最大值，这个给采用哈希来记录即可
//    直接遍历 nums1，然后在哈希表中找到对应值就可以
//    也就是先找到全部元素的下一个更大值，结果只需要nums1中的值的下一个；

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    // 单调栈：栈底大栈顶小
    stack<int> order_stack;
    // 记录的是nums2中每个值的下一个比自己大的值，
    // key：nums2中任一值；values：在nums2中key值后面第一个比key值大得值
    // 方便找到nums1中每个值得下一个更大值
    unordered_map<int, int> seen;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int curr = nums2[i];
        while (!order_stack.empty() && curr >= order_stack.top())
        {
            order_stack.pop();
        }
        // p判断是否为空
        seen[curr] = order_stack.empty() ? -1 : order_stack.top();
        //入栈
        order_stack.push(curr);
    }

    // 遍历nums1根据哈希来找答案
    vector<int> ans(n1, 0);
    for (int i = 0; i < n1; i++)
    {
        ans[i] = seen[nums1[i]];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
