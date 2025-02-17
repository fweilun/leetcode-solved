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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0;i < n;i++){
            if (lists[i]){
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(!pq.empty()){
            auto [x, id] = pq.top();
            ListNode* next = new ListNode(x);
            pq.pop();
            if (lists[id]){
                pq.push({lists[id]->val, id});
                lists[id] = lists[id]->next;
            }
            temp->next = next;
            temp = temp->next;
        }
        return dummy->next;
        
    }
};