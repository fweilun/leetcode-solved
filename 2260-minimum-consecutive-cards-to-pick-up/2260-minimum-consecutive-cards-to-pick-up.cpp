class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int s=0, e=0, n=cards.size(), window=n+1;
        unordered_set<int> store;
        while(e<n){
            while (s<e&&store.find(cards[e]) != store.end()){
                store.erase(cards[s++]);
                window=min(window, e-s+2);
            }
            while (e-s+2>window){
                store.erase(cards[s++]);
            }
            store.insert(cards[e++]);
        }
        return window==n+1?-1:window;
    }
};