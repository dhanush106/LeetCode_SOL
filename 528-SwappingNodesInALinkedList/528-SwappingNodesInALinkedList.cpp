// Last updated: 7/6/2026, 12:01:24 PM
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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL){
            return nullptr;
        }
        int len = leng(head);
        ListNode* temp = head;
        int pos = (len-k)+1;
        ListNode* slow = NULL;
        for(int i=1;i<k;i++){
            temp = temp->next;
        }
        slow=temp;
        temp = head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        ListNode* fast = temp;
        int t = slow->val;
        slow->val = fast->val;
        fast->val = t;
        return head;
    }
};