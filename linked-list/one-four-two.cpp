// 142. 环形链表 II

// 解题思路：快慢指针
// 说明同时从头节点和相遇节点出发的两个指针，每次走 1 步，最终会在入口处相遇。

#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            while(slow != head){
                slow = slow->next;
                head = head->next;
            }
            return head;
        }
    }
    return nullptr;
}

