class Solution {
public:
    int t;
    int solve(vector<int>& nums, int s, int e){
        if (s>e){return -1;}
        int mid = (s+e)/2;

        if (nums[mid] > t){
            return solve(nums, s, mid-1);
        }else if(nums[mid] < t){
            return solve(nums, mid+1, e);
        }else{
            return mid;
        }   
        // never
        return -1;
    }

    int solve_right(vector<int>&nums, int s,int e){
        // fix s, find e
        if (s > e){
            return s-1;
        }
        int mid = (s+e)/2;
        if (nums[mid] == t){
            return solve_right(nums, mid+1, e);
        }else{
            return solve_right(nums, s, mid-1);
        }   
    }
    int solve_left(vector<int>&nums, int s,int e){
        // fix e, find s
        if (s > e){
            return e+1;
        }
        int mid = (s+e)/2;
        if (nums[mid] == t){
            return solve_left(nums, s, mid-1);
        }else{
            return solve_left(nums, mid+1, e);
        }   
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        t = target;
        int r = solve(nums, 0, nums.size()-1);
        if (r == -1) return {-1, -1};
        return {solve_left(nums, 0, r), solve_right(nums, r, nums.size()-1)};
        
    }
};