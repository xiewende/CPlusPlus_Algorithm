// 1110. 删点成林

// 解题思路：dfs实现后续遍历，递归判断某个节点是否需要删除

// 若某节点需要删除，它需要做两件事
//     1、删除该节点的父节点的某个子(左右)节点需要设置为空，需要返回nullptr给父节点指向
//     2、该节点的左右节点应该重新成为二叉树的新根节点，添加到结果中
// 若某节点不需要删除，直接返回该节点

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* dfs(TreeNode* node, unordered_set<int> delete_set, vector<TreeNode*> &ans){
    if(node == nullptr){
        return nullptr;
    }
    //dfs
    node->left = dfs(node->left, delete_set, ans);
    node->right = dfs(node->right, delete_set, ans);
    // 当前节点要删除
    // 1、左右子节点放到结果中，
    // 2、返回nullptr给其父节点指向
    if(delete_set.count(node->val)){
        if(node->left != nullptr){
            ans.push_back(node->left);
        }
        if(node->right != nullptr){
            ans.push_back(node->right);
        }
        return nullptr;
    }
    // 当前节点不删除，直接返回该节点
    return node;
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    // 构建delete 的集合
    unordered_set<int> delete_set;
    for(auto curr : to_delete){
        delete_set.emplace(curr);
    }
    // 构建答案
    vector<TreeNode *> ans;
    //最后返回的是根节点，要判断
    TreeNode *node = dfs(root, delete_set, ans);
    if(node!=nullptr){
        ans.push_back(node);
    }
    return ans;
}


// bool is_root 定义该节点是否为潜在根节点，若某节点需要删除，则该节点的左右子树节点为潜在根节点设为true
TreeNode* dfs1(TreeNode* node, bool is_root, unordered_set<int> delete_set, vector<TreeNode*> &ans){
    if(node == nullptr){
        return nullptr;
    }
    bool deleted = delete_set.count(node->val) > 0 ? true : false;  // 判断该节点是否需要删除，进而判断该节点的左右子树是否为潜在根节点
    //dfs
    node->left = dfs1(node->left, deleted, delete_set, ans);
    node->right = dfs1(node->right, deleted, delete_set, ans);
    // 当前节点要删除
    // 返回nullptr给其父节点指向
    if(deleted){
        return nullptr; 
    }else
    {
        // 不删除，判断是否是潜在的根节点,是的话需要添加到结果中
        if(is_root){
            ans.emplace_back(node);
        }
        return node;
    }
}

vector<TreeNode*> delNodes1(TreeNode* root, vector<int>& to_delete) {
    // 构建delete 的集合
    unordered_set<int> delete_set;
    for(auto curr : to_delete){
        delete_set.emplace(curr);
    }
    // 构建答案
    vector<TreeNode *> ans;
    //最后返回的是根节点，要判断
    TreeNode *node = dfs1(root, true, delete_set, ans);
    // if(node!=nullptr){
    //     ans.push_back(node);
    // }
    return ans;
}

