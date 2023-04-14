// 面试题 02.08. 环路检测

// 解题思路：

// 1、哈希表
//     哈希表记录遍历的节点，若存在则是存在环，返回即可

// 2、快慢指针
//     慢指针，一次走一步；快指针，一次走两步
//     1）判断是否相遇：若快慢指针相遇则是有环的，
//     2）判断环的起点
//         在原链表的头节点 和 上述快慢指针的相遇点 这两个指针分别一步一步走，相遇点就是 环的起点；用公式证明

#include<iostream>
#include<unordered_set>

using namespace std;

struct ListNode {  
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希表
ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    while (head != nullptr) {
        if (visited.count(head)) {
            return head;
        }
        visited.insert(head);
        head = head->next;
    }
    return nullptr;
}

// 快慢指针遍历
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    bool flag = false;
    while(slow != nullptr & fast != nullptr ){
        slow = slow->next;
        if(fast->next == nullptr){
            break;
        }
        fast = fast->next->next;
        if(slow == fast){
            flag = true;
            break;
        }
    }

    if(flag){
        while(true){
            if(slow == head){
                break;
            }
            slow = slow->next;
            head = head->next;
        }
        return head;
    }else{
        return nullptr;
    }
}


int main(){
    ListNode *a =  new ListNode(1);
    ListNode *b =  new ListNode(2);
    // ListNode *c =  new ListNode(0);
    // ListNode *d =  new ListNode(4);
    // ListNode *e =  new ListNode(5);
    // ListNode *f =  new ListNode(2);
    a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = b;
    // e->next = f;
    ListNode *ans = detectCycle(a);
    cout << ans->val;
    // while(ans !=nullptr){
    //     cout << ans->val;
    //     ans = ans->next;
    // }
    return 0;
}