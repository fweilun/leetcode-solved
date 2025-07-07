class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& v1, const vector<int>& v2){
            return (v1[0] != v2[0]) ? v1[0] < v2[0] : v1[1] < v2[1];
        });
        priority_queue<int, vector<int>, greater<int>> store;
        int idx=0, out=0;
        int n=events.size();
        for (int i=1;i<=100000;++i){
            while (idx<n&&events[idx][0]<=i){
                store.push(events[idx++][1]);
            }
            while (store.size()&&store.top()<i) store.pop();
            if (store.size()){
                // cout << store.top()  << endl;
                ++out;
                store.pop();
            }
        }
        return out;
    }
};

// [3, 5]
// [3, 5]
// [3, 6]
// [3, 7]
// [6, 7]


