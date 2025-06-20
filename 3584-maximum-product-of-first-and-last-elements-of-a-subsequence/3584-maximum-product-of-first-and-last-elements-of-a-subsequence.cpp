class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int l=0, r=0, minDist=max(m-1, 0), n=nums.size();
        r=minDist;
        long long pos_max=-9999999999999;
        long long neg_min=9999999999999;
        long long out=-9999999999999;
        while (r<n) {
            while (l<=r-minDist){
                pos_max = max(pos_max, static_cast<long long>(nums[l]));
                neg_min = min(neg_min, static_cast<long long>(nums[l]));
                ++l;
            }
            if (nums[r]<0){
                out = max(out, neg_min*nums[r]);
            }else {
                out = max(out, pos_max*nums[r]);
            }
            ++r;
        }
        return out;
    }
};