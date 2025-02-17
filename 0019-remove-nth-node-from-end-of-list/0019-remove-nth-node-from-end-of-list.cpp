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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if (!head->next) return nullptr;
        ListNode* org = head;
        queue<ListNode*> q;
        while (head){
            q.push(head);
            if (q.size() > n + 1){
                q.pop();
            }
            head = head->next;
        }
        if (q.size() == n){
            return org->next;
        }
        if (n == 1){
            q.front()->next = nullptr;    
        }else{
            q.front()->next = q.front()->next->next;
        }
        return org;
    }
};