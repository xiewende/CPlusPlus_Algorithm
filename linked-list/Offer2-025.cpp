// 剑指 Offer II 025. 链表中的两数相加

// 解题思路：

// 1、直接对应位置相加，然后递归处理进位的问题

// 2、逆序相关，才有栈，分别入栈，相加即可

// 3、翻转再来操作

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int dfs(ListNode* node){
    if(node == nullptr){
        return 0;
    }
    int jinwei = dfs(node->next);
    int sum = node->val + jinwei;
    node->val = sum % 10;
    jinwei = sum / 10;
    return jinwei;
}
// 先对应位置相加，再来递归处理进位的问题
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l1_head = l1;
    ListNode *l2_head = l2;
    int len1 = 0;
    while(l1_head!=nullptr){
        len1++;
        l1_head = l1_head->next;
    }
    int len2 = 0;
    while(l2_head!=nullptr){
        len2++;
        l2_head = l2_head->next;
    }

    ListNode *fast;
    ListNode *slow;
    int diff = 0;
    if(len1 > len2){
        fast = l1;
        slow = l2;
        diff = len1 - len2;
    }else{
        fast = l2;
        slow = l1;
        diff = len2 - len1;
    }

    ListNode *now = fast;
    int count = 0;
    while(fast!=nullptr){
        if(count >= diff){
            fast->val = fast->val + slow->val;
            slow = slow->next;
        }
        count++;
        fast = fast->next;
    }

    //修改进位的事情
    ListNode *head = now;
    int jinwei = dfs(now);
    if(jinwei >=1 ){
        ListNode* preHead = new ListNode(1);
        preHead->next = head;
        return preHead;
    }else{
        return head;
    }
}


// 用栈模拟
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1 -> val);
        l1 = l1 -> next;
    }
    while (l2) {
        s2.push(l2 -> val);
        l2 = l2 -> next;
    }
    int carry = 0;
    ListNode* ans = nullptr;
    while (!s1.empty() or !s2.empty() or carry != 0) {
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode -> next = ans;
        ans = curnode;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ListNode *l1 =  new ListNode(7);
    ListNode *b =  new ListNode(2);
    ListNode *c =  new ListNode(4);
    ListNode *d =  new ListNode(3);
    l1->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;

    ListNode *l2 =  new ListNode(5);
    ListNode *e =  new ListNode(6);
    ListNode *f =  new ListNode(4);
    l2->next = e;
    e->next = f;
    f->next = nullptr;

    // ListNode *head = a;
    // int jinwei = dfs(a);
    // cout << jinwei;

    ListNode *head = addTwoNumbers(l1, l2);
    return 0;
}
