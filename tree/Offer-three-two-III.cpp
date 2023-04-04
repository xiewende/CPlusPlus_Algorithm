// 剑指 Offer 32 - III. 从上到下打印二叉树

// 解题思路
// 层序遍历，然后利用队列先进先出的特性，首先将root节点压入队列，然后若左右节点不为空，
// 则将左右节点分别压入队列，而这些左右节点又成为下一层的根节点。 所以将根节点数值压入数组之后，将其pop出来，
// 所以最后队列为空时，层序遍历完成。

#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 在II翻转一下中间数组就好
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr){
        return {};
    }
    queue<TreeNode *> myqueue;
    vector<vector<int>> ans;
    myqueue.push(root);
    while(!myqueue.empty()){
        int size = myqueue.size(); // 用来判断遍历到哪一层了
        vector<int> curr;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = myqueue.front();
            myqueue.pop();
            curr.emplace_back(node->val);
            if (node->left != nullptr)
            {
                myqueue.push(node->left);
            }
            if(node->right != nullptr){
                myqueue.push(node->right);
            }
        }
        ans.push_back(curr);
    }
    for (int i = 0; i < ans.size();i++)
    {
        if(i % 2 == 1){
            reverse(ans[i].begin(),ans[i].end());
        }
    }
    return ans;
}

vector<vector<int>> levelOrder1(TreeNode* root) {
    if(root == nullptr){
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    bool isOrderLeft = true;

    while (!nodeQueue.empty())
    {
        deque<int> levelList;
        int size = nodeQueue.size();
        for (int i = 0; i < size; ++i)
        {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            //插入的时候采用双端队列
            if (isOrderLeft)
            {
                levelList.push_back(node->val);
            }
            else
            {
                levelList.push_front(node->val);
            }

            // 插入队列
            if (node->left)
            {
                nodeQueue.push(node->left);
            }
            if (node->right)
            {
                nodeQueue.push(node->right);
            }
        }
        ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
        isOrderLeft = !isOrderLeft;
    }

    return ans;

}