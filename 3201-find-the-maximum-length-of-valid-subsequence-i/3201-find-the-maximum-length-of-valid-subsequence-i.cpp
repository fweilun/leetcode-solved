class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int temp=-1;
        int out=0, zeros=0, ones=0;
        for (int& x:nums) {
            x%=2;
            if (x!=temp) {
                temp=x;
                ++out;
            }
            ones+=x;
        }
        zeros = nums.size() - ones;

        return max(out, max(zeros, ones));
    }
};