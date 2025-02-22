class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0, e=nums.size()-1, cnt=0;
        while(s<=e){
            while(e>=0&&nums[e]==val){
                e--;
                cnt++;
            }
            if (s>=e) break;
            
            if (nums[s]==val){
                int temp = nums[s];
                nums[s]=nums[e];
                nums[e]=temp;
            }
            s++;
        }
        return nums.size()-cnt;
    }
};