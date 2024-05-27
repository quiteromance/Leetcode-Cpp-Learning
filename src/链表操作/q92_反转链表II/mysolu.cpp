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
        // 有点取巧，直接把left到rigth之间的数字压栈弹出，并没有执行链表反转操作
        // 记录left前一个结点和right后面一个节点，反转
        vector<int> Stack;
        int count = 1;
        ListNode *cur = head;
        while(count != left){
            cur = cur->next;
            count++;
        }
        while(count <= right){
            Stack.push_back(cur->val);
            count++;
            cur = cur->next;
        }
        cur = head;
        count = 1;
        while(count != left){
            cur = cur->next;
            count++;
        }
        while(count <= right){
            cur->val = Stack.back();
            Stack.pop_back();
            count++;
            cur = cur->next;
        }
        return head;
    }
};