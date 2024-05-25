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
    ListNode* reverseList(ListNode* head) {
        // 使用了三个指针分别指向当前节点，前一节点和后一节点
        ListNode *pre;
        ListNode *cur;
        ListNode *forward;
        pre = head;
        if(head == nullptr) return head; //如果给的节点是空那么返回空指针
        if(pre->next == nullptr){// 如果给的链表只有一个节点那么直接返回就可以
            return head;
        }
        cur = pre->next;
        if(cur->next == nullptr){// 如果给的链表只有俩个节点
            cur->next = pre;
            pre->next = nullptr;
            return cur;
        }
        forward = cur->next;
        // 如果有三个以上的节点
        pre->next = nullptr; // 先将pre指向空
        while(forward){// 当forward不是空的时候，将cur指向pre，将pre移动到cur，然后将cur移动到forwar
            cur->next = pre;
            pre = cur;
            cur = forward;
            forward = forward->next;
        }
        cur->next = pre;// 最后一步将cur指向pre，返回
        head = cur;
        return head;
    }
};

//时间复杂度O(N),空间复杂度O(1)