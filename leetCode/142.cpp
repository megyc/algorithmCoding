/**
 * 142. 环形链表 II
*/

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
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr &&fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {//链表有环
                ListNode* index = head;
                while (index != fast) {
                    index = index->next;
                    fast = fast->next;
                }
                return index;
            }
        }
        //链表无环
        return nullptr;
    }
};