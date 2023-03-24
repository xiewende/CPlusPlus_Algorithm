// 剑指 Offer 18. 删除链表的节点

#include<iostream>

using namespace std;

struct ListNode {  
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val) {

    ListNode *begin = new ListNode(0);
    ListNode *pre = new ListNode(0);
    pre->next = head;
    begin = pre;
    while (head!=nullptr)
    {
        if(head->val == val){
            pre->next = head->next;
        }
        head = head->next;
        pre = pre->next;
    }
    return begin->next;
}