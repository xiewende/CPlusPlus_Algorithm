// 面试题 04.05. 合法二叉搜索树

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


bool dfs(TreeNode* root, int low, int large){
    if(root == nullptr ){
        return true;
    }
    if(root->val <= low || root->val >= large){
        return false;
    }

    return dfs(root->left, low, root->val) && dfs(root->right, root->val, large);
}

bool isValidBST(TreeNode* root) {
    if(root == nullptr){
        return true;
    }
    return dfs(root, LONG_MIN, LONG_MAX);
}


TreeNode* prev=nullptr;
bool dfs(TreeNode* root){
    if(!root) return true;
    bool left=dfs(root->left);
    bool mid=true;
    if(prev != nullptr){
        if(root->val <= prev->val){
            mid = false;
        }
    }
    prev=root;
    bool right=dfs(root->right);
    return left && mid && right;

}
bool isValidBST(TreeNode* root) {
    return dfs(root);
}