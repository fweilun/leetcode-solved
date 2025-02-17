
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* tmp=dummy;
        while (list1 && list2){
            if (list1->val > list2->val){
                tmp->next = new ListNode(list2->val);
                list2 = list2->next;
            }else{
                tmp->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            tmp = tmp->next;
        }
        while (list1){
            tmp->next = new ListNode(list1->val);
            list1 = list1->next;
            tmp = tmp->next;
        }
        while (list2){
            tmp->next = new ListNode(list2->val);
            list2 = list2->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};