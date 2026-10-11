
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // Check whether k nodes are available
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        // Reverse only if a complete group of k exists
        if (count == k) {
            curr = reverseKGroup(curr, k);

            // Reverse the current group
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }

            head = curr;
        }

        return head;
    }
};
