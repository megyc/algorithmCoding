/**
 * 92. 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode dummy(0, head);
        ListNode* beforeReverse = &dummy;
        ListNode* firstReverse;
        ListNode* first;
        ListNode* second;
        int index = 1;
        //找到交换开始的位置
        while (index < left) {
            beforeReverse = beforeReverse->next;
            index++;//index表示first现在的位置
        }
        first = firstReverse = beforeReverse->next;//记录交换序列中第一个
        second = first->next;//排除了left == right 的情况
        index++;//index表示second现在的位置
        while (index <= right) {//反转
            index++;
            ListNode* temp = second->next;
            second->next = first;
            first = second;
            second = temp;
        }
        //链接反转部分
        beforeReverse->next = first;
        firstReverse->next = second;
        return dummy.next;
    }
};