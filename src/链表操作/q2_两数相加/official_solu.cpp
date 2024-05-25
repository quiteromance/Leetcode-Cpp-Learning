
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            //condition ? expr1 : expr2 
            //如果 l1 不是空指针（即，它指向了某个对象），则 n1 被赋值为 l1->val，其中 l1->val 表示访问 l1 指向对象的 val 成员。如果 l1 是空指针（即，它不指向任何对象），则 n1 被赋值为 0。
            int n2 = l2 ? l2->val: 0;

            //这么写的意思就是将两个链表看成是相同长度的进行遍历，如果一个链表较短则在前面补 0
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            //如果head是空，就创建一个新节点让head tail都指向它，如果不为空就创建新节点让tail的下一位指向它
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};


//时间复杂度：O(max⁡(m,n))，其中 mmm 和 nnn 分别为两个链表的长度。我们要遍历两个链表的全部位置，而处理每个位置只需要 O(1) 的时间。

//空间复杂度：O(1)。注意返回值不计入空间复杂度。

