// Last updated: 7/6/2026, 12:00:34 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL|| head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;

            fast = fast->next->next;
        }
        ListNode* curr = slow;
        prev->next = curr->next;
        delete curr;
        return head;
    }
};