class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(), m=queries.size();
        auto canMakeZero=[&](int k){
            vector<int> rcd(n+1, 0);
            for (int i=0;i<k;i++){
                rcd[queries[i][0]]+=queries[i][2];
                rcd[queries[i][1]+1]-=queries[i][2];
            }
            int tot_de=0;
            for (int i=0;i<n;i++){
                tot_de+=rcd[i];
                if (tot_de<nums[i]) return false;
            }
            return true;
        };

        int l=0, r=m-1;
        while (l<=r){
            int mid=(l+r)/2;
            if (canMakeZero(mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return canMakeZero(l)?l:-1;
    }
};