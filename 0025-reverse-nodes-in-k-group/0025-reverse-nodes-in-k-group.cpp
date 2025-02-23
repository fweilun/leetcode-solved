class Solution {
public:
    ListNode* check(ListNode* head, int k){
        while(k--&&head){
            head=head->next;
        }
        return head;
    }
    ListNode* reverse(ListNode* head, int k){
        ListNode* first=head;
        ListNode* last=nullptr;
        ListNode* temp=head;
        ListNode* next=nullptr;
        while(temp&&k--){
            next=temp->next;
            temp->next=last;
            last=temp;
            temp=next;
        }
        first->next=temp;
        return first;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head||k==1) return head;
        ListNode* dummy=new ListNode(-1, head);
        head=dummy;
        ListNode* next;
        ListNode* to_run;
        while(true){
            next=check(head, k);
            if (!next) break;
            to_run=head->next;
            head->next=next;
            head=reverse(to_run, k);
        }
        return dummy->next;
    }
};