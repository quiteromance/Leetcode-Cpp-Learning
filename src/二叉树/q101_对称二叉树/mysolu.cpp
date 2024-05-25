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
    bool isSymmetric(TreeNode* root) {
        // 使用层序遍历每一层，判断每一层是否是回文串
        if(root == nullptr) return true; // 如果为空，返回true
        queue<TreeNode*> Que; //层序遍历创建队列
        Que.push(root);
        vector<int> vec; //创建记录的向量
        while(!Que.empty()){
            int size = Que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                if(Que.front()->left != nullptr) {
                    Que.push(Que.front()->left);
                    vec.push_back(Que.front()->left->val);
                }
                else
                    vec.push_back(-10); // 如果是空节点，返回-10；这里比较投机取巧
                
                if(Que.front()->right != nullptr){
                    Que.push(Que.front()->right);
                    vec.push_back(Que.front()->right->val);
                } 
                else
                    vec.push_back(-10);
                            
                Que.pop();
            }
            if(!isMoslems(vec)) return false;
        }
        return true;
    }

    bool isMoslems(vector<int> vec){
        // 判断一个节点向量是否是回文串
        for(int i = 0; i < vec.size()/2; i++){
            if(vec[i] != vec[vec.size()-1-i]) return false;
        }
        return true;
    }
};