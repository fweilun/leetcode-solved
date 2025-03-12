class Solution {
public:
    int upper(vector<int>& nums, int l, int r){
        if (l>r){return l;}
        int m=(l+r)/2;
        if (nums[m]>0){
            return upper(nums, l, m-1);
        }else{
            return upper(nums, m+1, r);
        }
        return -1;
    }
    int lower(vector<int>& nums, int l, int r){
        if (l>r){return r;}
        int m=(l+r+1)/2;
        if (nums[m]<0){
            return lower(nums, m+1, r);
        }else{
            return lower(nums, l, m-1);
        }
        return -1;
    }

    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        // cout << lower(nums, 0, n-1) << endl;
        // cout << upper(nums, 0, n-1) << endl;
        // return 0;
        return max(lower(nums, 0, n-1)+1, n-upper(nums, 0, n-1));
    }
};
// -1, 0