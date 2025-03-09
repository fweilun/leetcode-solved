class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<long long>> store;
        for (int i=0;i<n;i++){
            store.push_back({i,nums1[i],nums2[i], 0});
        }
        sort(store.begin(), store.end(), [](const vector<long long>& a, const vector<long long>& b) {
        return a[1] < b[1];
    });
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        long long sum=0;
        for (int i = 0; i < n; i++) {
            store[i][3] = sum;
            
            sum += store[i][2];
            pq.push(store[i][2]);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (i>0&&store[i][1]==store[i-1][1]){
                store[i][3]=store[i-1][3];
            }
        }
        vector<long long>out(n, 0);
        for (int i=0;i<n;i++){
            out[store[i][0]]=store[i][3];
        }
        
        return out;
    }
};