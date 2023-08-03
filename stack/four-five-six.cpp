// 456. 132 模式

// 解题思路：单调栈, 栈底大栈顶小

// nums[i]<nums[k]<nums[j] 其中 i<j<k

// 栈存储属于 j 位置的值，也就是最大值，k 位置的值来自栈顶，但是需要记录 max—k，所以肯定满足k<j的，
// 然后遍历i判断是都小于k位置的值即可。

// 就是单调栈维护的是3，max_k维护的是2，枚举的是1， max_k来源与单调栈，所以其索引一定大于栈顶的元素，但其值一定小于栈顶元素，故栈顶元素就是3，即找到了对“32”。 
// 于是当出现nums[i] < max_k时，即找到了"12"，这个时候一定会有3个元素的，而栈顶3必定大于2，故也大于1，即满足“132”

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool find132pattern(vector<int>& nums) {
    stack<int> s;
    int max_k = INT_MIN;
    for (int i = nums.size() - 1; i >= 0;i--)
    {
        // 只需要在此判断是否存在“1”的值小于“32”中的“2”值max_k了，若满足，直接返回
        if(nums[i]<max_k){
            return true;
        }
        // 栈顶元素为大，得到max_k, 就是满足“32”的过程了，就是max_k就是“32”中的“2”的值
        while(!s.empty() && nums[i]>s.top()){
            max_k = max(max_k, s.top());
            s.pop();
        }
        // 当前元素入栈
        s.push(nums[i]);
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 4};
    bool ans = find132pattern(nums);
    cout<<ans;
    return 0;
}

