// 面试题 02.04. 分割链表

#include<iostream>

using namespace std;

struct ListNode {  
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode *small =  new ListNode(0);
    ListNode *large = new ListNode(0);
    ListNode *head_small = small;
    ListNode *head_large = large;

    while(head != nullptr){
        if(head->val >= x ){
            large->next = head;
            large = large->next;
        }else{
            small->next = head;
            small = small->next;
        }
        head = head->next;
    }
    large->next = nullptr;
    small->next = head_large->next;

    return head_small->next;
}


int main(){
    ListNode *a =  new ListNode(1);
    ListNode *b =  new ListNode(4);
    ListNode *c =  new ListNode(3);
    ListNode *d =  new ListNode(2);
    ListNode *e =  new ListNode(5);
    ListNode *f =  new ListNode(2);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    ListNode *ans = partition(a, 3);
    while(ans !=nullptr){
        cout << ans->val;
        ans = ans->next;
    }
    return 0;
}