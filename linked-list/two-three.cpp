// 23. 合并 K 个升序链表

// 优先队列

// 1、将所有链表的头节点值放入队列中，存储的结构<val, idx>,val就是该节点的值，idx就是该节点所在链表在lists中的下标，方向出队的时候找到该链表
// 2、队列按照小到大排序，取队列头节点，也就是最小节点，
// 3、取出就可以构造返回链表，然后找到该节点的下一个节点存入队列中
// 4、以此反复，知道队列为空，


#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    // 优先队列，按照小到大排序，《val,idx》，val:节点值，idx:该节点在lists中的第几个链表下标
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // 记录每个链表当前遍历的节点下标。全为1是因为我们会先将头节点放到队列中
    vector<int> idHash(n,1);
    ListNode *head;
    for(int i=0;i<n;i++){
        head = lists[i];
        if(head != nullptr){
            q.push({head->val, i});
        }
    }
    ListNode *pre = new ListNode(0);
    head = pre;
    while(!q.empty()){
        // 出队并且生成链表
        pair<int, int> curr = q.top();
        q.pop();
        ListNode *node = new ListNode(curr.first);
        pre->next = node;
        pre = node;
        // 寻找下一个入队
        ListNode *currList = lists[curr.second]; // 找到出队的链表，curr.second该节点所在lists中链表的下标，
        int curridx = idHash[curr.second]; //  找该节点所在所链表遍历到哪个节点
        // 遍历链表，找到需要入队的节点
        while(curridx>0 && currList!=nullptr){
            currList = currList->next;
            curridx--;
        }
        // 不为空，则入队，可能某个链表遍历完了，所以需要判断
        if(currList!=nullptr){
            q.push({currList->val, curr.second});
            idHash[curr.second]++;
        }
    }
    return head->next;
}