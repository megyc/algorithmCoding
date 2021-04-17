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
    //方法一：遍历一遍数出链表的长度，然后再找到倒数第n个节点并删除
    //方法二：从head到链表尾全部入栈，然后弹出n个
    //方法三：前一个指针与后一个指针保持n的距离，后一个指针到尾部时，前一个就是倒数第n个
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //加上虚拟头节点可以避免头节点被删除时需要考虑的情况
        ListNode* dummy = new ListNode(head->val, head);
        ListNode* slow;
        ListNode* fast;
        slow = dummy;
        fast = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        ListNode* ans = dummy->next;
        //回收
        delete dummy;
        return ans;
    }
};