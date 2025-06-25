class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using pii=pair<int, int>;
        vector<vector<int>> out;
        auto cmp = [&](const pii &x, const pii &y){
            return nums1[x.first] + nums2[x.second] > nums1[y.first] + nums2[y.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        for (int i=0;i<nums1.size();i++) pq.push(make_pair(i, 0));

        while (k--) {
            auto [i, j]=pq.top(); pq.pop();
            out.push_back({nums1[i], nums2[j]});
            if (j+1>=nums2.size()) continue;
            pq.push({i, j+1});
        }
        return out;
    }
};

