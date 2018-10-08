//请实现一个函数，用来判断一颗二叉树是不是对称的。
//注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == nullptr){
            return true;
        }
        TreeNode* left = pRoot->left;
        TreeNode *right = pRoot->right;

        return IsSymmetricalCore(left, right);
    }
    bool IsSymmetricalCore(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        else if(left && right && left->val == right->val){
            return IsSymmetricalCore(left->left, right->right) 
            && IsSymmetricalCore(left->right, right->left);
        }
        return false;
    }
};
