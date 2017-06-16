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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                ptr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            else {
                ptr->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            ptr = ptr->next;
        }
        while (l1 != NULL) {
            ptr->next = new ListNode(l1->val);
            l1 = l1->next;
            ptr = ptr->next;
        }
        while (l2 != NULL) {
            ptr->next = new ListNode(l2->val);
            l2 = l2->next;
            ptr = ptr->next;
        }
        ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
};