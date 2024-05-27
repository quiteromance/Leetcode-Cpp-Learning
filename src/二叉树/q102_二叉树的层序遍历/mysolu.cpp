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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_vec;
        queue<TreeNode*> que; // 用于层序遍历
        if(root == nullptr) return level_vec;
        que.push(root); 
        while(!que.empty()){
            vector<int> vec; // 用于记录每一层的节点值
            int size = que.size();
            for(int i = 0; i < size; i++){
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);
                vec.push_back(que.front()->val);
                que.pop();
            }
            level_vec.push_back(vec);

        }
        return level_vec;
    }
};


//***********************************************************方案2************************************************************//
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_vec;
        queue<TreeNode*> que; // 用于层序遍历
        if(root == nullptr) return level_vec;
        que.push(root); 
        unordered_map<TreeNode*,int> map; //用于记录每一个节点对应的层
        map[que.front()] = 1;
        while(!que.empty()){
            vector<int> vec; // 用于记录每一层的节点值
            int index = map[que.front()];
            while(map[que.front()] == index){
                if(que.front()->left != nullptr) {
                    que.push(que.front()->left);
                    map[que.front()->left] = map[que.front()] + 1;
                }
                if(que.front()->right != nullptr) {
                    que.push(que.front()->right);
                    map[que.front()->right] = map[que.front()] + 1;
                }
                vec.push_back(que.front()->val);
                que.pop();
            } 
            level_vec.push_back(vec);
        }
        return level_vec;
    }
};