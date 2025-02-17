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
    ListNode* swapPairs(ListNode* head) {
        ListNode* result = head;
        bool stop{false};

        ListNode* last;
        while (head){
            if (stop){
                swap(last->val, head->val);
            }
            last = head;
            head = head->next;
            stop = !stop;
        }
        return result;
    }
};