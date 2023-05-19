// 剑指 Offer II 052. 展平二叉搜索树
#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 先中序遍历，再生成
void inorder(TreeNode *node, vector<int> &res) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }

TreeNode *increasingBST(TreeNode *root) {
    vector<int> res;
    inorder(root, res);

    TreeNode *dummyNode = new TreeNode(-1);
    TreeNode *currNode = dummyNode;
    for (int value : res) {
        currNode->right = new TreeNode(value);
        currNode = currNode->right;
    }
    return dummyNode->right;
}

// 在中序遍历的过程修改指针
// TreeNode *resNode
void inorder(TreeNode *node) {
    if (node == nullptr) {
        return;
    }
    inorder(node->left);

    // 在中序遍历的过程中修改节点指向
    resNode->right = node;
    node->left = nullptr;
    resNode = node;

    inorder(node->right);
}

TreeNode *increasingBST(TreeNode *root) {
    TreeNode *dummyNode = new TreeNode(-1);
    resNode = dummyNode;
    inorder(root);
    return dummyNode->right;
}

TreeNode* increasingBST(TreeNode* root) {

}