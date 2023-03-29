// 946. 验证栈序列
// 剑指 Offer 31. 栈的压入、弹出序列

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int length = pushed.size();
    stack<int> mystack;
    int idx = 0;
    for (int i = 0; i < length; i++)
    {
        //入栈
        mystack.push(pushed[i]);

        //在栈不为空的情况下判断栈顶元素和输出元素是否对应
        while(!mystack.empty() && mystack.top() == popped[idx]){
            mystack.pop();
            idx++;
        }
    }
    return mystack.empty();
}

int main(){
    vector<int> pushed{1, 2};
    vector<int> poped{1, 2};
    bool ans = validateStackSequences(pushed, poped);
    cout << ans;
    return 0;
}