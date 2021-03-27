/**
 * 剑指 Offer 06. 从尾到头打印链表
 * /
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
    vector<int> reversePrint(ListNode* head) {
        if(!head){
            return{};
        }
        vector<int>a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};