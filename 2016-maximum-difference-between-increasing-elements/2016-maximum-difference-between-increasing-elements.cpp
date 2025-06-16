class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int out=-1;
        int minval = INT_MAX;
        for (int &x:nums){
            if (x<=minval){
                minval = x;
            } else {
                out = max(out, x-minval);
            }
        }
        return out;
    }
};