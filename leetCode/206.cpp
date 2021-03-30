/**
 * 反转链表
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
//迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* ans= new ListNode(head->val,NULL);
        head = head->next;
        while(head){
            ListNode* temp = new ListNode(head->val,head->next);
            temp->next = ans;
            ans = temp;
            head = head->next;
        }
        return ans;
    }
};

//迭代法：双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};
//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head ==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};