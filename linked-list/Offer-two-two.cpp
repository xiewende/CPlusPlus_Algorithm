// 剑指 Offer 22. 链表中倒数第k个节点

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
    int length = 0;
    ListNode *tem = head;
    while(tem != nullptr){
        length++;
        tem = tem->next;
    }

    int cha = length - k;

    while(cha>0){
        head = head->next;
        cha--;
    }

    return head;
}