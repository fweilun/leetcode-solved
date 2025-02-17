class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        
        int ptr=1;
        for (int i = 1;i < n;i++){
            if (nums[i] != nums[i-1]){
                nums[ptr++] = nums[i];
            }
        }
        for (int i = 0;i < n-ptr;i++){
            nums.pop_back();
        }
        
        return ptr;
        
    }
};