/**
 * 2. 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum;
        int carry = 0;
        ListNode dummy;
        ListNode* ptr = &dummy;
        while (l1 && l2) {//假如还有一个链表没加完
            ptr->next = new ListNode();//创建一个新节点
            ptr = ptr->next;//指针移动到新节点
            sum = l1->val + l2->val + carry;//得到带进位的和
            carry = sum / 10;//得到新的进位
            sum %= 10;//得到val
            ptr->val = sum;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ptr->next = new ListNode();//创建一个新节点
            ptr = ptr->next;//指针移动到新节点
            sum = l1->val +  carry;//得到带进位的和
            carry = sum / 10;//得到新的进位
            sum %= 10;//得到val
            ptr->val = sum;
            l1 = l1->next;
        }
        while (l2) {
            ptr->next = new ListNode();//创建一个新节点
            ptr = ptr->next;//指针移动到新节点
            sum = l2->val +  carry;//得到带进位的和
            carry = sum / 10;//得到新的进位
            sum %= 10;//得到val
            ptr->val = sum;
            l2 = l2->next;
        }
        if (carry != 0) {
            ptr->next = new ListNode();//创建一个新节点
            ptr = ptr->next;//指针移动到新节点
            ptr->val = carry;
        }
        return dummy.next;
    }
};