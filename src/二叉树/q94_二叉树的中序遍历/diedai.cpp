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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        vector<TreeNode*> stack;
        while(root!=nullptr || !stack.empty()){
            if(root != nullptr){
                stack.push_back(root);
                root = root->left;
            }
            else{
                root = stack.back();
                vec.push_back(root->val);
                stack.pop_back();
                root = root->right;
            }
        }
        return vec;          
        }   
};