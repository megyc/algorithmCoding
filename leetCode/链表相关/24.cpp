/**
 * 24. 两两交换链表中的节点 
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummySecond(0,head);
        ListNode dummyFirst(0,&dummySecond);
        ListNode* first = &dummyFirst;
        ListNode* second = &dummySecond;
        ListNode* temp;
        while (first->next->next && second->next->next) {
            temp = second->next->next;
            (first->next->next)->next = (second->next->next)->next;
            temp->next = (first->next->next);
            second->next = temp;
            first = first->next->next;
            second = second->next->next;
        }
        return dummySecond.next;
    }
};