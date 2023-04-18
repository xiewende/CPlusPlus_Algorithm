// 1026. 节点与其祖先之间的最大差值

// 解题思路：递归

// 记录祖先节点的最大值和最小值，
// 到子孙节点直接相比较即可

#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode* root, int large, int small){
    if(root == nullptr){
        return 0;
    }

    int diff = max(abs(root->val - large), abs(root->val - small));

    large = max(large, root->val);
    small = min(small, root->val);

    diff = max(diff, dfs(root->left, large, small));
    diff = max(diff, dfs(root->right, large, small));

    return diff;
}

int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
}