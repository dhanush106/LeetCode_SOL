// Last updated: 7/6/2026, 12:03:32 PM
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
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        int len = leng(head);
        k = k % len;
        if(k==0){
            return head;
        }
        cout<<"LEN :: "<<len<<" k :: "<<k<<endl;
        ListNode* second = head;
        ListNode* secondHead = NULL;
        ListNode* tail = NULL;
        int pos = len - k;
        for(int i=1;i<pos;i++){
            second = second->next;
        }
        secondHead = second->next;
        second->next = NULL;
        tail = secondHead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        cout<<tail->val;
        tail->next = head;

        return secondHead;
    }
};