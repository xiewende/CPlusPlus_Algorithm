// 剑指 Offer 06. 从尾到头打印链表

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> reversePrint(ListNode* head) {

    vector<int> ans;
    while(head != nullptr){
        ans.emplace(ans.begin(), head->val);
        head = head->next;
    }
    return ans;
}