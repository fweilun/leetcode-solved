class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<bool> store(101, false);
        int n = nums.size();
        int sum = 0;
        bool empty = true;
        for (int &x: nums) {
            if (x > 0 && !store[x]){
                store[x] = true;
                empty = false;
                sum += x;
            }
        }
        if (empty) { 
            return *max_element(nums.begin(), nums.end());
        }
        return sum;
    }
};