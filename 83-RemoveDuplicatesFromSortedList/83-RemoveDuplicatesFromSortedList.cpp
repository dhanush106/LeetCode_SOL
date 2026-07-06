// Last updated: 7/6/2026, 12:03:17 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return nullptr;
        }
        ListNode* temp = head;
        while(temp!=NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode* curr = temp->next;
                temp->next = curr->next;
                delete curr;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }
};