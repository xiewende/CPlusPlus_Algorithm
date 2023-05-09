// 剑指 Offer II 049. 从根节点到叶节点的路径数字之和

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// dfs
int dfs(TreeNode* root, int preSum){
    if(root == nullptr){
        return 0;
    }
    int sum = preSum * 10 + root->val;

    if (root->left == nullptr && root->right == nullptr) {
        return sum;
    } else {
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

// bfs
int sumNumbers1(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int sum = 0;
    queue<TreeNode*> nodeQueue;
    queue<int> numQueue;
    nodeQueue.push(root);
    numQueue.push(root->val);
    while (!nodeQueue.empty()) {
        TreeNode* node = nodeQueue.front();
        int num = numQueue.front();
        nodeQueue.pop();
        numQueue.pop();
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        if (left == nullptr && right == nullptr) {
            sum += num;
        } else {
            if (left != nullptr) {
                nodeQueue.push(left);
                numQueue.push(num * 10 + left->val);
            }
            if (right != nullptr) {
                nodeQueue.push(right);
                numQueue.push(num * 10 + right->val);
            }
        }
    }
    return sum;
}

// 回溯
int sum = 0;
int num = 0;
int sumNumbers(TreeNode* root) {
    dfs(root);
    return sum;
}
void dfs(TreeNode* node){
    if(node == nullptr) return;
    num = num * 10 + node->val;
    if(node->left == nullptr && node->right == nullptr){
        sum += num;
    }
    dfs(node->left);
    dfs(node->right);
    num = (num - node->val) / 10;
}
