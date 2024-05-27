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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 这个是用反转链表来做的，但是分类讨论比较多
        ListNode *pre;
        ListNode *cur;
        ListNode *forward;
        ListNode *Left;
        ListNode *PreLeft;
        pre = head;
        int count = 1;
        if(left == right){
            return head;// 如果相等直接返回head
        }
        if(left != 1){// 如果头节点不需要反序
            while(count < left-1){
                pre = pre->next;
                count++;
            }
            PreLeft = pre;
            Left = pre->next;
            pre = pre->next;
            cur = pre->next;
            count++;      
            while(count < right){
                ListNode *forward = cur->next;
                cur->next = pre;
                pre = cur;
                cur = forward;
                count++;
            }
            PreLeft->next = pre;
            Left->next = cur;
            return head;
        }
        if(left == 1){// 如果头节点需要反序
            cur = pre->next; 
            while(count < right){
                ListNode *forward = cur->next;
                cur->next = pre;
                pre = cur;
                cur = forward;
                count++;
            }
            head->next = cur;
            return pre;
        }
        return head;
    }
};