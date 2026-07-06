// Last updated: 7/6/2026, 12:02:10 PM
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip middle for odd length
        if(fast != NULL){
            slow = slow->next;
        }

        // Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare
        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};