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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp = l1;
        
        while (l2 != nullptr) {
            

            tmp->val = tmp->val+l2->val;
            l2 = l2->next;

            if (tmp->next == nullptr) {
                tmp->next = l2;
                l2 = nullptr;
            }
            tmp = tmp->next;
        }
        tmp = l1;
        
        while (tmp != nullptr){
            
            if (tmp->val >= 10) {
                tmp->val-=10;
                if (tmp->next == nullptr){
                    tmp->next = new ListNode(1);
                    break;
                }
                
                tmp = tmp->next;
                tmp->val += 1;
            }
            else {
                tmp = tmp->next;
            }
        }

        return l1;
    }
};