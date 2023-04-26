// 剑指 Offer II 021. 删除链表的倒数第 n 个结点

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head;
    ListNode *slow;
    ListNode *pre_head = new ListNode(-1);
    pre_head->next = head;
    while(fast != nullptr){
        n--;
        if(n == 0){
            slow = pre_head;
        }
        fast = fast->next;
        if(n < 0){
            slow = slow->next;
        }
    }

    slow->next = slow->next->next;
    return pre_head->next;
}

int main(int argc, char const *argv[])
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    int k = 2;

    ListNode *ans = removeNthFromEnd(a, k);

    while(ans!=nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}

