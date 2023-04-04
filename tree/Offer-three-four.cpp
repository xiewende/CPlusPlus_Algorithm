// 剑指 Offer 34. 二叉树中和为某一值的路径

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recursion(vector<vector<int>> &ans, vector<int> &curr, TreeNode* root, int target){
    if(root == nullptr){
        return;
    }
    curr.push_back(root->val);
    target = target - root->val;
    if(root->left == nullptr && root->right == nullptr && target==0){
        ans.push_back(vector<int>{curr.begin(), curr.end()});
    recursion(ans, curr, root->left, target);
    recursion(ans, curr, root->right, target);
    curr.pop_back();
    return;
}

vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    recursion(ans, curr, root, target);
    return ans;
}