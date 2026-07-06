// Last updated: 7/6/2026, 12:03:49 PM
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
    int leng(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next==NULL){
            return nullptr;
        }
        int len = leng(head);
        ListNode* temp = head;
        int pos = (len-n)+1;
        if(pos == 1){
            ListNode* curr = head;
            head = head->next;
            delete curr;
            return head;
        }
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        cout<<temp->val;
        ListNode *curr = temp->next;
        temp->next=curr->next;
        delete curr;
        return head;
    }
};