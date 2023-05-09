// 剑指 Offer II 044. 二叉树每层的最大值

#include<iostream>
#include<queue>
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

vector<int> largestValues(TreeNode* root) {
    if(root == nullptr){
        return {};
    }
    vector<int> ans;
    queue<TreeNode *> myqueue; // 队列实现层次遍历
    myqueue.push(root);
    while(!myqueue.empty()){
        int size = myqueue.size(); // 表示一层
        int curr_max = -INT_FAST64_MIN;
        for (int i = 0; i < size;i++)
        {
            TreeNode *curr = myqueue.front();
            myqueue.pop();
            curr_max = max(curr_max, curr->val);
            // 下一层的入队
            if(curr->left!=nullptr){
                myqueue.push(curr->left);
            }
            if(curr->right!=nullptr){
                myqueue.push(curr->right);
            }
        }
        //遍历完一层，添加结果
        ans.emplace_back(curr_max);
    }
    return ans;
}