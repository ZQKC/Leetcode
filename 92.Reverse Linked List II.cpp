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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *head_head = new ListNode(0);
        head_head->next = head;
        
        ListNode *beg = head_head;
        for (int i = 1; i < m; ++i) {
            beg = beg->next;
        }
        if (m == n) {
            return head;
        }
        
        ListNode *node = beg->next, *end = beg->next;
        for (int i = m; i <= n; ++i) {
            ListNode *tmp = node->next;
            
            ListNode *beg_next = beg->next;
            beg->next = node;
            node->next = beg_next;
            
            node = tmp;
        }
        end->next = node;
        head = head_head->next;
        delete head_head;
        
        return head;
    }
};