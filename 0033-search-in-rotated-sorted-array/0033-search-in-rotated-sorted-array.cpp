class Solution {
public:
    int t;
    int findMax(vector<int>& nums, int left, int right){
        if (right - left == 1) return left;
        // left > mid or mid > right, gap
        int mid = (left+right)/2;
        if (nums[left] > nums[mid]){
            return findMax(nums, left, mid);
        }else{
            return findMax(nums, mid, right);
        }
        
    }
    int solve(vector<int> nums, int left, int right){
        if (left > right) return -1;
        int mid = (left + right)/2;
        int idx = mid % nums.size();
        if (t < nums[idx]){
            return solve(nums, left, mid-1);
        }else if (nums[idx] < t){
            return solve(nums, mid+1, right);
        }else{
            return idx;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        t = target;
        int n = nums.size();
        /*
        edge case 
        1. array is not rotated
        2. array size is less than 2 
        */ 
        
        // 1
        if (nums[0] < nums[n-1]){
            return solve(nums, 0, n-1);
        }
        // 2
        if (nums.size() == 1){
            return nums[0] == target ? 0 : -1;
        }
        


        int right = findMax(nums, 0, nums.size()-1);
        t = target;
        int left = right + 1;
        right += nums.size();
        return solve(nums, left, right);
        
    }
};