// 24. 两两交换链表中的节点

// 解题思路：两个指针+头节点，边遍历边翻转

#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

ListNode* swapPairs(ListNode* head) {
    ListNode *preHead = new ListNode(0, head);
    ListNode *tem = head;

    while (tem->next != nullptr && tem->next->next != nullptr)
    {
        ListNode *begin = tem->next;
        ListNode *end = tem->next->next;
        tem->next = end;
        begin->next = end->next;
        end->next = begin;
        tem = begin;
    }
    return head->next;
}

// 递归
ListNode* swapPairs(ListNode* head) {
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
}


