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
    int jinwei = 0;
    ListNode *head = new ListNode(0);
    ListNode *ans = head;
    while(l1!=nullptr || l2!=nullptr || jinwei==1){
        int ll1 = l1 != nullptr ? l1->val : 0;
        int ll2 = l2 != nullptr ? l2->val : 0;
        int sum = ll1 + ll2 + jinwei;
        int curr = sum % 10;
        jinwei = curr / 10;
        auto currNode = new ListNode(curr);
        head->next = currNode;
        head = currNode;
        if(l1 != nullptr){
            l1 = l1->next;
        }
        if(l2 = nullptr){
            l2 = l2->next;
        }
    }
    return ans->next;
}