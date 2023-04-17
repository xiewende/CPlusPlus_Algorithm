// 面试题 04.03. 特定深度节点链表

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 层序遍历
vector<ListNode*> listOfDepth(TreeNode* tree) {
    if(tree == nullptr){
        return {};
    }
    vector<ListNode*> ans;
    queue<TreeNode *> myqueue;
    myqueue.push(tree);
    while(!myqueue.empty()){
        int size = myqueue.size(); //记录每层
        ListNode *head = new ListNode(0);
        ListNode *save = head;
        // 记录每层的遍历
        for (int i = 0; i < size;i++)
        {
            TreeNode *curr = myqueue.front();
            myqueue.pop();
            ListNode *node = new ListNode(curr->val);
            head->next = node;
            head = head->next;
            if(curr->left != nullptr){
                myqueue.push(curr->left);
            }
            if(curr->right != nullptr){
                myqueue.push(curr->right);
            }
        }
        ans.push_back(save->next);
    }
    return ans;
}