class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        while (true){
            if (nums[s]<nums[e]){
                return nums[s];
            }
            int mid=(s+e)/2;
            if (s==mid)return min(nums[s], nums[e]);
            if (nums[s]>nums[mid])e=mid;
            else if (nums[s]<nums[mid])s=mid+1;
        }
        return -1;
    }
};