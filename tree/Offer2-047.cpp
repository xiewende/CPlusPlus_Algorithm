// 剑指 Offer II 047. 二叉树剪枝

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool bfs(TreeNode* root) {

    if(root == nullptr){
        return true;
    }

    bool left = bfs(root->left);
    bool right = bfs(root->right);
    
    if(left && right && root->val==0){
        return true;
    }
    
    if (left == true){
        root->left = nullptr;
    }
    if (right == true){
        root->right = nullptr;
    }

    return false;
}

TreeNode* pruneTree(TreeNode* root) {
    bool ans = bfs(root);
    if(ans){
        return nullptr;
    }
    return root;
}