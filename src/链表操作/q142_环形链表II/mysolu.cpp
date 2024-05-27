/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while(fast != slow ){
            if(fast == nullptr){
                return nullptr;
            }            
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};