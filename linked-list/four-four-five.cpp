// 445. 两数相加 II

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 定义两个栈，并且入栈
    stack<int> s1;
    stack<int> s2;
    while(l1 != nullptr){
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr){
        s2.push(l2->val);
        l2 = l2->next;
    }
    int jinwei = 0;
    ListNode *head = new ListNode(0);
    while(!s1.empty() || !s2.empty()){
        int curr = s1.top() + s2.top() + jinwei;
        int tem = curr % 10;
        jinwei = curr / 10;
        ListNode *nextNode = new ListNode(tem);
        nextNode->next = head->next;
        head->next = nextNode;
        // head = head->next;
        s1.pop();
        s2.pop();
    }
    // 判断链表长度是否一致，也就是栈是否为空
    // 若为空，则判断最后进位即可
    // 若不为空，则继续添加长链表的值
    if(s1.empty() && s2.empty()){
        if(jinwei == 1){
            ListNode *nextNode = new ListNode(jinwei);
            nextNode->next = head->next;
            head->next = nextNode;
        }
        return head->next;
    }else
    {
        if(!s1.empty()){
            while(!s1.empty()){
                int curr = s1.top() + jinwei;
                int tem = curr % 10;
                jinwei = curr / 10;
                ListNode *nextNode = new ListNode(tem);
                nextNode->next = head->next;
                head->next = nextNode;
                s1.pop();
            }
        }else
        {
            while(!s2.empty()){
                int curr = s2.top() + jinwei;
                int tem = curr % 10;
                jinwei = curr / 10;
                ListNode *nextNode = new ListNode(tem);
                nextNode->next = head->next;
                head->next = nextNode;
                s2.pop();
            }
        }
        // 判断最后的进位
        if(jinwei == 1){
            ListNode *nextNode = new ListNode(jinwei);
            nextNode->next = head->next;
            head->next = nextNode;
        }
        return head->next;
    }
}