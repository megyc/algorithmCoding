/**
 * 707. 设计链表
*/

class MyLinkedList {
private:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode* pre;
        ListNode(int val,ListNode* next,ListNode* pre):val(val),next(next),pre(pre) {};
    };
    ListNode* head;
    ListNode* tail;
    int size;
public: 
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new ListNode(0, nullptr, nullptr);
        tail = new ListNode(0, nullptr, head);
        head->next = tail;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int temp = -1;
        ListNode* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
            temp++;
            if (temp == index) return curr->val;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val, head->next, head);
        ListNode* temp = head->next;
        head->next = newNode;
        temp->pre = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val, tail, tail->pre);
        ListNode* temp = tail->pre;
        tail->pre = newNode;
        temp->next = newNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        } 
        if (index == size) {
            addAtTail(val);
            return;
        } 
        int temp = 0;
        ListNode* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
            temp++;
            if (index == temp) {
                ListNode* newNode = new ListNode(val,curr->next,curr);
                ListNode* tempNode = curr->next;
                curr->next = newNode;
                tempNode->pre = newNode;
                size++;
                return;
            }
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        int temp = -1;
        ListNode* curr = head;
        while(head->next != tail) {
            curr = curr->next;
            temp++;
            if (temp == index) {
                curr->pre->next = curr->next;
                curr->next->pre = curr->pre;
                size--;
                delete curr;
                return;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */