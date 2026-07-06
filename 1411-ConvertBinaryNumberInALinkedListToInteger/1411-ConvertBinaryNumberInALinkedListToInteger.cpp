// Last updated: 7/6/2026, 12:00:54 PM
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
    //     if(head == NULL){
    //         return 0;
    //     }
    //     int count = 0;
    //     ListNode* temp = head;
    //     while(temp!=NULL){
    //         temp=temp->next;
    //         count++;
    //     }
    //     return count;
    // }
    int getDecimalValue(ListNode* head) {
        // if(head->next == NULL){
        //     return head->val;
        // }
        // int len = leng(head);
        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // while(curr != NULL){
        //     ListNode* newnode = curr->next;
        //     curr -> next = prev;
        //     prev = curr;
        //     curr = newnode;
        // }
        // int num = 0;
        // while(prev!=NULL){
        //     num += (1 << (len - 1)) * prev->val;
        //     prev= prev->next;
        //     len--;
        // }
        // return num;
        int num = 0;
        while(head){
            num = num * 2 + head->val;
            head = head->next;
        }
        return num;
    }
};