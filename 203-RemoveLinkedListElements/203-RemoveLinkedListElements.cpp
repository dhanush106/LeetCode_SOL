// Last updated: 7/6/2026, 12:02:20 PM
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
        ListNode* newhead = NULL;
        ListNode* curr = newhead;
        ListNode* temp = head;
        while(temp!=NULL){
            if(newhead == NULL && temp->val != val){
                newhead = new ListNode(temp->val);
                curr=newhead;
                temp = temp->next;
            }else{
                if(temp->val != val){
                    curr->next = new ListNode(temp->val);
                    curr = curr->next;
                    temp = temp->next;
                }else{
                    temp = temp->next;
                }
            }
        }
        return newhead;
    }
};