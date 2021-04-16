
/**
 * 203. 移除链表元素
 */

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*  newHead = new ListNode(0);
        newHead->next = head;
        ListNode* p = newHead;
        while (p->next != nullptr) {
            if (p->next->val == val) {
                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            } else {
                p = p->next;
            }
        }
        return newHead->next;//不能返回head，因为head可能被删除了
    }
};