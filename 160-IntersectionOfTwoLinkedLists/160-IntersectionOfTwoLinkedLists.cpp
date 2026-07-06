// Last updated: 7/6/2026, 2:12:29 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* slow = headA;
        // ListNode* fast = headB;
        // while(slow!=fast){
        //     slow = (slow == NULL) ? headB : slow->next;
        //     fast = (fast == NULL) ? headA : fast->next;
        // }
        // return fast;
        // unordered_set<ListNode*> od;
        // ListNode* p1 = headA, *p2 = headB;
        // while(p1 != NULL){
        //     od.insert(p1);
        //     p1 = p1->next;
        // }
        // while(p2 != NULL){
        //     if(od.count(p2)){
        //         return p2;
        //     }
        //     od.insert(p2);
        //     p2 = p2->next;
        // }
        // return nullptr;

        ListNode* slow = headA;
        ListNode* fast = headB;
        while(slow != fast){
            slow = (slow == NULL) ? headB : slow->next;
            fast = (fast == NULL) ? headA : fast->next;
        }
        return slow;
    }
};