// 剑指 Offer II 026. 重排链表

// 解题思路；把节点放到数组中，前后指针逐步该表指向
// 1、找中点，翻转后面，合并前后
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

void reorderList(ListNode* head) {
    vector<ListNode*>vt;
    while(head){
        vt.push_back(head);
        head=head->next;
    }
    int i=0,j=vt.size()-1;
    while(i<j){
        vt[j]->next=vt[i]->next;
        vt[i]->next=vt[j];
        i++,j--;
    }
    vt[i]->next=nullptr;
}

int main(int argc, char const *argv[])
{
    ListNode l1;
    l1.val = 1;
    ListNode l2;
    l2.val = 2;
    ListNode l3;
    l3.val = 3;
    ListNode l4;
    l4.val = 4;
    // ListNode l5;
    // l5.val = 5;

    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    // l4.next = &l5;

    reorderList(&l1);

    for(ListNode *curr = &l1; curr!=NULL; curr = curr->next){
        cout << curr->val << endl;
    }



    return 0;
}


