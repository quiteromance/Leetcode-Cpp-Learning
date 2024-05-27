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
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {nullptr} ;
        return generateTree(1,n);
    }
   

    vector<TreeNode*> generateTree(int start, int end){
        if(start > end) return {nullptr};
        vector<TreeNode*> allTree;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTree = generateTree(start, i-1);
            vector<TreeNode*> rightTree = generateTree(i+1, end);
       
            for(auto left:leftTree){
                for(auto right:rightTree){
                    TreeNode *curTree = new TreeNode(i);
                    curTree->left = left;
                    curTree->right = right;
                    allTree.emplace_back(curTree);
                }
                
            }
        }
        return allTree;
        
    }
};