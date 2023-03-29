// 剑指 Offer 28. 对称的二叉树

// 解题思路：
// 1、递归
// 满足对称二叉树：对于树中文艺对称节点 L，R，一定有
// L.val == R.val:即两对称节点值相等
// L.left.val == R.right.val: 即L的左子节点和R的右子节点对称
// L.right.val == R.left.val ：即L的右子节点和R的左子节点堆成

// 2、队列迭代 
// 初始化时我们把根节点入队两次。每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像）
// 然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
bool check(TreeNode* L, TreeNode* R){
    if(L == nullptr && R == nullptr){
        return true;
    }
    if(!L || !R){ // 两个节点一个为空一个不为空
        return false;
    }
    return L->val==R->val && check(L->left, R->right) && check(L->right, R->left);
}

//队列实现广度优先遍历
bool check1(TreeNode *u, TreeNode *v) {
    queue <TreeNode*> q;
    q.push(u); q.push(v);
    while (!q.empty()) {
        u = q.front(); q.pop();
        v = q.front(); q.pop();
        if (!u && !v) continue;
        if ((!u || !v) || (u->val != v->val)) return false;

        q.push(u->left); 
        q.push(v->right);

        q.push(u->right); 
        q.push(v->left);
    }
    return true;
}

bool isSymmetric(TreeNode* root) {
    // return check(root, root);
    return check1(root, root);
}