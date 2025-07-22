class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0, out=0, sum=0;
        unordered_map<int, int> occ;
        while (r<n){
            ++occ[nums[r]];
            sum += nums[r];
            while (occ[nums[r]] > 1){
                --occ[nums[l]];
                sum -= nums[l];
                ++l;
            }
            ++r;
            out = max(out, sum);
        }
        return out;
    }
};