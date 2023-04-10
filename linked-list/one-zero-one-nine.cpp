// 1019. 链表中的下一个更大节点
// 解题思路
// 1、双重遍历
// 2、单调栈

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 直接双重遍历
vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    ListNode *curr;
    bool visited = false;
    while(head != nullptr){
        visited = false;
        curr = head->next;
        while(curr != nullptr){
            if(curr->val > head->val){
                visited = true;
                break;
            }
            curr = curr->next;
        }
        int num = visited == true ? curr->val : 0;
        ans.push_back(num);
        head = head->next;
    }
    return ans;
}

// 单调栈 1 从右往左看
// 反转链表
ListNode *reverseList(ListNode *head){
    ListNode *pre = nullptr;
    ListNode *curr = head;
    while(curr){
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
// 单调栈，底大顶小
vector<int> nextLargerNodes1(ListNode* head){
    head = reverseList(head);
    stack<int> mystack;
    vector<int> ans;
    for (ListNode *curr = head; curr; curr = curr->next)
    {
        while(!mystack.empty() && mystack.top() <= curr->val){
            mystack.pop();
        }
        // 栈顶元素就是底i哥节点的下一个更大的元素
        ans.push_back(mystack.empty() ? 0 : mystack.top());
        mystack.push(curr->val);
    }
    // 由于是倒着记录答案的，返回前要把答案反转
    reverse(ans.begin(), ans.end());
    return ans;
}

// 单调栈 2 从左往右看 底大顶小
vector<int> nextLargerNodes(ListNode *head) {
    vector<int> ans;
    stack<pair<int, int>> st; // 单调栈（节点值，节点下标）
    for (auto cur = head; cur; cur = cur->next) {
        while (!st.empty() && st.top().first < cur->val) {
            ans[st.top().second] = cur->val; // 用当前节点值更新答案
            st.pop();
        }
        // 当前 ans 的长度就是当前节点的下标
        st.emplace(cur->val, ans.size());
        ans.push_back(0); // 占位
    }
    return ans;
}

