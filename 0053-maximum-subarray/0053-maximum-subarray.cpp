class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for (int i = 1;i < nums.size();i++){
            nums[i] = max(nums[i-1], 0) + nums[i];
            nums[0] = max(nums[0], nums[i]);
        }
        return nums[0];
    }
};