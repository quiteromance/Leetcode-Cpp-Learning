/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> stack;
        ListNode *p = head;
        while(p){
            stack.push_back(p->val);
            p = p->next;
        }
        while(head){
            if(head->val!=stack.back()){
                return false;
            }
            stack.pop_back();
            head = head->next;
        }
        return true;
    }
};