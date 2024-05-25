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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 用一个指针指向l1，用另一指针指向l2，创建新的节点head，用p指针指向head，pre指针用于指向前一节点
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode;
        ListNode *p = head;
        ListNode *pre;
        int index = 0; //index用来进位
        while(p1 != nullptr && p2 != nullptr){ 
            // 如果链表当前不为空，当进位为0的时候，创建一个新的节点，值为两个节点数值相加并且记录进位；如果有进位就把进位加上去。
            if(index == 0){
                
                p->val = (p1->val + p2->val)%10;
                index = (p1->val + p2->val - p->val)/10;
            }
            else{
                p->val = (p1->val + p2->val +1 )%10;
                index = (p1->val + p2->val +1 - p->val)/10 ;
            }
            // p1 p2指向下一个节点
            p1 = p1->next;
            p2 = p2->next;
            ListNode *newNode = new ListNode; // 创建新的节点，p指针的下一个位置指向新的节点
            p->next = newNode;
            pre = p; 
            p = p->next;//p指针指向新的节点，pre指针指向当前p指针前一个节点
        }

        // 当p1是空且p2还有数据的时候，直接将pre指向p2
        if(p1 == nullptr && p2 != nullptr){
            pre->next = p2;
            if(index == 1){
                // 如果有进位就进位，一直指向空指针位置
                while(p2 != nullptr){
                    if(index == 1){
                        p2->val++;
                    }
                    index = p2->val/10;
                    p2->val = p2->val%10;
                    pre = p2;
                    p2 = p2->next;
                }
                if(p2 == nullptr && index == 1){
                    // 当p2为空且有一个进位的时候，还需要创建一个数值为1的节点，让pre指向它
                    ListNode *newNode = new ListNode(1,nullptr);
                    pre->next = newNode;
                }
            }
        }
        // 当p2是空且p1还有数据的时候，直接将pre指向p2
        if(p2 == nullptr && p1 != nullptr){
            pre->next = p1;
            if(index == 1){
                while(p1 != nullptr){
                    if(index == 1){
                        p1->val++;
                    }
                    index = p1->val/10;
                    p1->val = p1->val%10;
                    pre = p1;
                    p1 = p1->next;
                }
                if(p1 == nullptr && index == 1){
                    ListNode *newNode = new ListNode(1,nullptr);
                    pre->next = newNode;
                }
            }
        }

        // 当都为空的时候，直接判断进位就可以
        if(p2 == nullptr && p1 == nullptr){
            if(index == 1){
                    p->val = 1;
                    p->next = nullptr;
            }
            else{
                pre->next = nullptr;
            }

        }

        return head;//返回head
    }
};