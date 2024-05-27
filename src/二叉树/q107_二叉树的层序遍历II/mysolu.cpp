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


/*
 * 用了两个栈，先用102的方法入栈，然后弹出就可以实现遍历了
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> vec1;
        vector<vector<int>> vec2;
        queue<TreeNode*> que;
        if(!root) return vec1; // 如果节点为空返回空数组;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;// 用于存放每一层节点值的向量,每一次都要置0
            for(int i = 0; i < size; i++){
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);
                vec.push_back(que.front()->val);
                que.pop();
            }
            vec1.push_back(vec);
        }
        while(!vec1.empty()){
            vec2.push_back(vec1.back());
            vec1.pop_back();      
        }
        return vec2;
    }
};