/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator()(ListNode *a, ListNode *b) {  
        if(a->val < b->val) 
            return 0;  
        return 1;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> que;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) 
                que.push(lists[i]);
        }
        
        ListNode *head = new ListNode(0);
        ListNode *ptr = head;
        while (!que.empty()) {
            ListNode *tmp = que.top();
            que.pop();
            
            ptr->next = new ListNode(tmp->val);
            ptr = ptr->next;
            
            if (tmp->next != NULL) {
                que.push(tmp->next);
            }
        }
        
        ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
};