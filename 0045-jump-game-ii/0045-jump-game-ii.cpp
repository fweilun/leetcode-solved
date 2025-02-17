class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> minj(n, 999999);
        minj[0] = 0;
        for (int i = 0;i < n;i++){
            for (int j = 1; j <= nums[i]; j++){
                if (i+j >= n){
                    break;
                }
                minj[i+j] = min(minj[i] + 1, minj[i+j]);
            }
        }
        return minj[n-1];
    }
};