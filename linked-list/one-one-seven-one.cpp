// 1171. 从链表中删去总和值为零的连续节点

// 前缀和，key:sum, value:链表节点

// 第一次遍历，记录前缀和和对应的节点，有相同的前缀和直接覆盖
// 第二次遍历，记录前缀和，在哈希表中找到相同的值，直接改变指针的指向；
// 两次遍历只关注开始和最后的前缀和

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode *preHead = new ListNode(0);
    preHead->next = head;
    //记录前缀和
    int preSum = 0; 
    // 哈希表
    unordered_map<int, ListNode*> seen;
    // 第一次遍历
    for (ListNode *node = preHead; node; node = node->next)
    {
        preSum += node->val;
        seen[preSum] = node;
    }

    preSum = 0;
    // 第二次遍历
    for (ListNode *node = preHead; node; node = node->next)
    {
        preSum += node->val;
        node->next = seen[preSum]->next;
    }

    return preHead->next;
}

// ListNode* removeZeroSumSublists(ListNode* head) {
//     ListNode *preHead = new ListNode(0);
//     preHead->next = head;
//     //记录前缀和
//     int preSum = 0; 
//     // 哈希表
//     unordered_map<int, ListNode*> seen;
//     // 一次遍历
//     for (ListNode *node = preHead; node; node = node->next)
//     {
//         preSum += node->val;

//         if(seen.count(preSum)){
//             seen[preSum]->next = node->next;
//         }else{
//             seen[preSum] = node;
//         }
//     }
//     return preHead->next;
// }