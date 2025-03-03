class Solution {
public:
    long long appealSum(string &s) {
        int n = s.size();
        vector<int> last_occ(26 ,-1 );
        long ans = 0;
        int pre_appeal = 0 ; 
        for(int i = 0; i < n; i++)
        {
            int cur_appeal = 0;
            cur_appeal = pre_appeal + (i +1)  - ( last_occ[s[i] - 'a'] +1);
            ans += cur_appeal;
            last_occ[s[i] - 'a'] = i;
            pre_appeal = cur_appeal;
        }
        return ans;
    }
};