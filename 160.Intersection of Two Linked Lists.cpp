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
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *pA = headA;
        while (pA->next != NULL) 
            pA = pA ->next;
        pA -> next = headA;
        
        ListNode *pB_s1 = headB, *pB_s2 = headB;
        while (1){
            pB_s1 = pB_s1->next != NULL ? pB_s1->next: NULL;
            pB_s2 = pB_s2->next != NULL && pB_s2->next->next != NULL ? pB_s2->next->next: NULL;
            if (pB_s1 == NULL || pB_s2 == NULL) {
                pA -> next = NULL;
                return NULL;
            }
            if (pB_s1 == pB_s2) 
                break;
        }
        ListNode *pB = headB;
        while (pB != pB_s1){
            pB = pB->next;
            pB_s1 = pB_s1->next;
        }
        pA -> next = NULL;
        return pB_s1;
    }
};