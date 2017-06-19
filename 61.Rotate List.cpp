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
    int listLen(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            head = head->next;
            ++len;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = listLen(head);
        if (len == 0 || k%len == 0) {
            return head;
        }
        k %= len;

        ListNode *pre = head, *ptr = head->next;
        for (int i = 1; i < len; ++i) {
            if (i == len - k) {
                break;
            }
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = NULL;
        pre = ptr;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = head;
        head = pre;
        return head;
    }
};