class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Find the length of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Connect tail to head to make it circular
        tail->next = head;
        
        // Find the new tail position: (len - k % len) steps from head
        k = k % len;
        int stepsToNewTail = len - k;
        ListNode* newTail = tail;
        while (stepsToNewTail > 0) {
            newTail = newTail->next;
            stepsToNewTail--;
        }
        
        // Break the cycle and set the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
