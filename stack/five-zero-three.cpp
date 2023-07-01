// 503. 下一个更大元素 II

// 解题思路：单调栈，底大上小

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> newNums(2*n);
    vector<int> ans(2*n);
    stack<int> order_stack;
    // for (int i = 0; i < 2 * n;i++)
    // {
    //     newNums[i] = nums[i % n];
    // }

    for (int i = 2 * n-1; i >=0 ;i--)
    {   
        // int num = nums[ i ];

        int num = nums[ i % n ];

        while(!order_stack.empty() && num >= order_stack.top()){
            order_stack.pop();
        }
        // 若空，则没有，否则就是栈顶元素
        ans[i] = order_stack.empty() ? -1 : order_stack.top();
        // 入栈
        order_stack.push(num);
    }

    return vector<int>(ans.begin(), ans.begin() + n);
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);
    for(auto curr:ans){
        cout << curr << " ";
    }
    return 0;
}

