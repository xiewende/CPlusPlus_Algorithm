// 1448. 统计二叉树中好节点的数目

// 递归即可，记录树路劲的最大值，若当前接节点大于等于最大值，则该节点满足条件，+1，同时需要更新最大值为该节点最大值

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

int dfs(TreeNode* root, int maxV){
    // 为null，直接返回0
    if(root == nullptr){
        return 0;
    }
    int ans = 0;
    // 判断当前节点是否满足条件
    if(root->val >= maxV){
        ans += 1;
    }
    // 更改最大值
    maxV = max(root->val, maxV);
    // 递归左, 右子树，答案相加返回
    ans += dfs(root->left, maxV);
    ans += dfs(root->right, maxV);
    return ans;
}


int goodNodes(TreeNode* root) {
    return dfs(root, INT_MIN);
}

int main(int argc, char const *argv[])
{
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(1);
    TreeNode *c = new TreeNode(4);
    TreeNode *d = new TreeNode(3);
    TreeNode *e = new TreeNode(1);
    TreeNode *f = new TreeNode(5);

    a->left = b;
    a->right = c;
    b->left = d;
    c->left = e;
    c->right = f;

    int ans = goodNodes(a);
    cout << ans;
    return 0;
}
