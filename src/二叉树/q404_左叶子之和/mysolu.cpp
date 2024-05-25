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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0; // 用于记录和
        int count = 0; //判断是否是左叶子
        vector<TreeNode*> stack;
        if(root ==nullptr) return 0;
        while(!stack.empty() || root != nullptr){ //中序遍历
            if(root!=nullptr){ // 如果root不是空节点，就一直往左节点走
                count ++; // 每走一步count就+1
                stack.push_back(root); 
                if(root->left == nullptr && root->right == nullptr && count != 1){ // 判断，如果是左子叶的话count不等于1
                    sum += root->val;
                } 
                root = root->left;      
            }
            else{
                    count = 0; //左边走完就要往右边走，只要往右边走，count就归零
                    root = stack.back()->right; 
                    stack.pop_back();
                }                                                       
        }
        return sum;
    } 
};