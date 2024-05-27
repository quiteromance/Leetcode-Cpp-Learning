/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, bool> vis;
    unordered_map<TreeNode*,TreeNode*> Map;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Map.insert({root, nullptr});
        fatherTree(root);
        while (p != nullptr) {
            vis[p] = true;
            p = Map[p];
        }

        while (q != nullptr) {
            if (vis[q]) return q;
            q = Map[q];
        }

        return nullptr;

    }

    void fatherTree(TreeNode* root){
        if(root == nullptr) return ;
        if(root->left!=nullptr) {
            Map.insert({root->left,root});
            fatherTree(root->left);
        }
        if(root->right!=nullptr){
            Map.insert({root->right,root});
            fatherTree(root->right);
        }
    }
};