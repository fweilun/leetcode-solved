class Solution {
public:
    int t;
    int solve(vector<int> &nums, int s, int e){
        if (s > e){ return s;}
        int mid = (s+e)/2;
        if (nums[mid] > t){
            return solve(nums, s, mid-1);
        }else if (nums[mid] < t){
            return solve(nums, mid+1, e);
        }else{
            return mid;
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        t = target;
        return solve(nums, 0, nums.size()-1);

        // int left = 0, right = nums.size()-1;
        // while (left <= right){
        //     int mid = (left + right)/2;
        //     if (target > nums[mid]){
        //         left = mid + 1;
        //     }else if (target < nums[mid]){
        //         right = mid - 1;
        //     }else{
        //         return mid;
        //     }
        // }
        // return left;
        
    }
};