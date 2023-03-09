#include<iostream>

// 力扣低21道题目

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
    ListNode* ans = new ListNode(0);
    ListNode* curr = ans;
    while(list1 != NULL and list2 != NULL){
        ListNode* next1 = new ListNode(0);
        if (list1->val < list2->val){
           curr->val = list1->val;
           list1 = list1->next;
        }else{
            curr->val = list2->val;
            list2 = list2->next;
        }
        curr->next = next1;
        curr = curr->next;
        
    }   

    curr->val = list1 != nullptr ? list1->val : list2->val;
    curr->next = list1 != nullptr ? list1->next : list2->next;

    return ans;

}

int main(){

    ListNode l1;
    l1.val = 1;
    ListNode l2;
    l2.val = 2;
    ListNode l3;
    l3.val = 4;
    l1.next = &l2;
    l2.next = &l3;

    for(ListNode *curr = &l1; curr!=NULL; curr = curr->next){
        cout << curr->val << endl;
    }

    ListNode ll1;
    ll1.val = 1;
    ListNode ll2;
    ll2.val = 3;
    ListNode ll3;
    ll3.val = 4;
    ll1.next = &ll2;
    ll2.next = &ll3;

    for(ListNode *curr = &ll1; curr!=NULL; curr = curr->next){
        cout << curr->val << endl;
    }


    // ListNode l1;
    // l1.val = 1;
    // ListNode l2;
    // l2.val = 2;
    // ListNode l3;
    // l3.val = 3;

    ListNode *ans;

    ans = mergeTwoLists(&l1, &ll1);

    for(ListNode *curr = ans; curr!=NULL; curr = curr->next){
        cout << curr->val << endl;
    }

    // 只能是指针模式
    // ListNode* lis = new ListNode(0);
    // cout<<lis->val;

    // 数组
    // ListNode arr[3] = {1,2,2};
    // for(int i=0;i<3;i++){
    //     cout << arr[i].val << endl;
    // }

    return 0 ;
}



