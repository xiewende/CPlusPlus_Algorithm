// 剑指 Offer 33. 二叉搜索树的后序遍历序列

// 解题思路：
// 一、递归思路，判断根节点的两端是否满足二叉搜索树的定义
// 算法步骤：判断给定的 postorder[i,j]是满足二叉搜索树 , 定义函数check(postorder,begin,end)递归来判断是否满足，begin和end就是给定的数组范围 
//     1、先遍历 postorder找到第一个大于根结点 postorder[j] 的 index 值
//     2、按照 index 划分这个向量的左右子树，左子树【i, index-1】,右子树【index, j-1】，j-1是因为去掉根节点
//     3、左子树是满足二叉搜索树的，不需要判断
//     4、需要判断右子树是否再满足二叉搜索树，定义 idx=index，index++ 来判断 postorder[idx] 是否大于 postorder[j], 
//        后面只需要判断 idx是否等于 j来判断右子树是否满足二叉搜索树。
//     5、最后调用递归来判断 右子树是否成立, 左子树内部是否满足, 右子树内部是否满足。
//     6、递归出口就是 i>=j

// 二、单调栈的辅助使用
// 后序遍历：左，右，根；后序遍历倒序：根，右，左。
// 定义祖先节点 parnet 为无穷大，
// 倒叙遍历给定的 postorder
//     1、若 postorder[i] > parnet; 代表节点 postorder[i] 在 parnet 的左子树，不满足二叉搜索树，返回false；
//     2、循环遍历 栈不为空，并且 postorder[i] < stack.top();  postorder[i] < stack.top()代表找到节点的左子树的父节点
//         parnet = stack.pop(); 更新祖先节点
//     3，无论前面怎么样，  postorder[i] 入栈
//     4、遍历的完就返回true；

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
bool check(vector<int>& postorder, int begin, int end){
    if(begin >= end) return true;
    int idx = begin;
    // 找到第一个大于根节点的值，左子树成立
    while (postorder[idx] < postorder[end])
    {
        idx++;
    }
    // 判断右子树是否成立
    int idx_right = idx;
    while (postorder[idx_right] > postorder[end])
    {
        idx_right++;
    }
    // 判断右子树是否成立, 左子树内部是否满足, 右子树内部是否满足
    return idx_right == end && check(postorder, begin, idx - 1) && check(postorder, idx, end-1);
}

bool verifyPostorder(vector<int>& postorder) {
    return check(postorder, 0, postorder.size() - 1);
}


// 单调栈
bool verifyPostorder1(vector<int>& postorder) {
    stack<int> mystack;
    int parnet = 0x3f3f3f3f;
    for (int i = postorder.size() - 1; i >= 0; i++){
        if(postorder[i] > parnet){
            return false;
        }
        while(!mystack.empty() && mystack.top()>postorder[i]){
            parnet = mystack.top();
            mystack.pop();
        }
        mystack.push(postorder[i]);
    }
    return true;
}
    