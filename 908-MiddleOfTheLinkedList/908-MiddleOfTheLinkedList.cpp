// Last updated: 7/6/2026, 12:01:06 PM
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
    // int leng(ListNode* head){
    //     int count = 0;
    //     while(head != NULL){
    //         count++;
    //         head = head->next;
    //     }
    //     return count;
    // }
    ListNode* middleNode(ListNode* head) {
        // int len = leng(head);
        // ListNode* temp = head;

        // ListNode* newhead = NULL;
        // int mid;
        // if(len%2 == 0){
        //     mid = (len/2);
        // }else{
        //     mid = (len/2);
        // }
        // ListNode* m = head;
        // for(int i=1;i<=mid;i++){
        //     m=m->next;
        // }
        // cout<<m->val;
        // return m;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};