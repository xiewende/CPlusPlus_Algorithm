// 剑指 Offer 27. 二叉树的镜像

#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
TreeNode* mirrorTree(TreeNode* root) {
    if(root == nullptr){
        return nullptr;
    }
    //递归左子树换
    TreeNode *left = mirrorTree(root->left);
    //递归右子树换
    TreeNode *right = mirrorTree(root->right);
    // 交换
    root->left = right;
    root->right = left;

    return root;
}

// 栈实现广度优先遍历
TreeNode* mirrorTree(TreeNode* root) {
    if(root == nullptr){
        return nullptr;
    }
    stack<TreeNode *> tree_stack;
    tree_stack.push(root);
    while(!tree_stack.empty()){
        TreeNode *node = tree_stack.top();
        tree_stack.pop();
        if(node->left != nullptr) //不为null，入队列
        {
            tree_stack.push(node->left);
        }
        if (node->right != nullptr) //不为null，入队列
        {
            tree_stack.push(node->right);
        }
        // 交换
        TreeNode *tem = node->left;
        node->left = node->right;
        node->right = tem;
    }

    return root;
}