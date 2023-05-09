// 剑指 Offer II 050. 向下的路径节点之和
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


void dfs(TreeNode* root, int targetSum, vector<long long>& nums, int& count){

    if(root == nullptr){
        return;
    }

    for (auto i = nums.begin(); i < nums.end(); i++) {
        *i = *i + root->val;
        if(*i == targetSum){
            count++;
        }
    }
    if(root->val==targetSum){
        count++;
    }
    nums.emplace_back(root->val);

    dfs(root->left, targetSum, nums, count);
    dfs(root->right, targetSum, nums, count);
    for (auto i = nums.begin(); i < nums.end(); i++) {
        *i = *i - root->val;
    }
    nums.pop_back();
}

int pathSum(TreeNode* root, int targetSum) {
    int ans = 0;
    vector<long long> nums;
    dfs(root, targetSum, nums, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    TreeNode *a = new TreeNode(1);
    // TreeNode *b = new TreeNode(5);
    // TreeNode *c = new TreeNode(3);
    // TreeNode *d = new TreeNode(2);
    // TreeNode *e = new TreeNode(3);
    // TreeNode *f = new TreeNode(-2);
    // TreeNode *g = new TreeNode(1);
    // TreeNode *h = new TreeNode(-3);
    // TreeNode *i = new TreeNode(11);

    // a->left = b;
    // a->right = h;

    // b->left = c;
    // b->right = d;

    // c->left = e;
    // c->right = f;

    // d->right = g;

    // h->right = i;

    int targtSum = 1;

    int ans = pathSum(a, targtSum);
    cout << ans;

    return 0;
}
