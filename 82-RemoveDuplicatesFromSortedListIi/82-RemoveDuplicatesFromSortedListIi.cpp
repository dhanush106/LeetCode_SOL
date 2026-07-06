// Last updated: 7/6/2026, 12:03:18 PM
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
        if(head == NULL || head->next == NULL){
            return head;
        }
        map<int,int> mp;
        ListNode* temp = head;
        while(temp != NULL){
            mp[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        ListNode* first = NULL;
        while(temp!=NULL){
            if(mp[temp->val]==1){
                first = temp;
                break;
            }
            temp = temp->next;
        }
        if (first == NULL)
            return NULL;
        ListNode* firstHead = first;
        temp = first->next;
        while(temp!=NULL){
            if(mp[temp->val]==1){
                first->next = temp;
                first = first->next;
            }
            temp= temp->next;
        }
        first->next = NULL;
        return firstHead;
    }
};