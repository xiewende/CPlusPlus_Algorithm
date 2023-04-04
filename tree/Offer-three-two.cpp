// 剑指 Offer 32 - I. 从上到下打印二叉树

// 解题思路
// 层序遍历，然后利用队列先进先出的特性，首先将root节点压入队列，然后若左右节点不为空，
// 则将左右节点分别压入队列，而这些左右节点又成为下一层的根节点。 所以将根节点数值压入数组之后，将其pop出来，
// 所以最后队列为空时，层序遍历完成。

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> levelOrder(TreeNode* root) {
    if(root == nullptr){
        return {};
    }
    queue<TreeNode *> myqueue;
    vector<int> ans;
    myqueue.push(root);
    while(!myqueue.empty()){
        TreeNode *curr = myqueue.front();
        myqueue.pop();
        ans.emplace_back(curr->val);

        if (curr->left != nullptr)
        {
            myqueue.push(curr->left);
        }
        if(curr->right != nullptr){
            myqueue.push(curr->right);
        }
    }
    return ans;
}