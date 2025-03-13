class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> rcd(n+1, 0);
        for (vector<int>& vec:queries){
            rcd[vec[0]]++;
            rcd[vec[1]+1]--;
        }
        int tot_de=0;
        for (int i=0;i<n;i++){
            tot_de+=rcd[i];
            if (tot_de<nums[i]) return false;
        }
        return true;
    }
};