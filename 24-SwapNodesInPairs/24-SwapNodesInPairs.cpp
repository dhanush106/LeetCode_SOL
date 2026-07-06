// Last updated: 7/6/2026, 12:03:44 PM
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next; 
        while(slow!=NULL && slow->next!=NULL){
            int temp = slow->val;
            slow->val = slow->next->val;
            slow->next->val = temp;
            slow=slow->next->next;
        }
        return head;
        
    }
};