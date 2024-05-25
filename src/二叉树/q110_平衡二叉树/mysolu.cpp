/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isBalanced(TreeNode* root) {
        return process(root).isBalanced;
    }

    class ReturnType{ // 新建一个类，包含树的高度和是否是平衡树信息
        public:
        int height;
        bool isBalanced;
        ReturnType(int hei, bool isB) : height(hei),isBalanced(isB) {}
    };

    ReturnType process(TreeNode* root){ // 返回是类的process过程
        if(root == nullptr) return ReturnType(0, true); // 如果是空指针直接返回true
        ReturnType left = process(root->left); // 左树遍历
        ReturnType right = process(root->right);// 右树遍历
        int height = left.height > right.height ? left.height : right.height ; // 树高为左右子树的最大值加1
        height++;
        bool isBalanced = (left.isBalanced && right.isBalanced) 
                        && (right.height - left.height == 1 || right.height - left.height == -1 || right.height - left.height == 0);
        return ReturnType(height,isBalanced);
    }

    
};