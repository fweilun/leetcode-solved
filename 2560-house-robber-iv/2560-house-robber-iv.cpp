class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        auto check=[&](int maxi){
            int need=k;
            int choseLast=false;
            for (int i=0;i<n&&need;i++){
                if (nums[i]<=maxi&&!choseLast){
                    need--;
                    choseLast=true;
                }else{
                    choseLast=false;
                }
            }
            if (!need) return true;
            return false;
        };
        int r = *max_element(nums.begin(), nums.end());
        int l = *min_element(nums.begin(), nums.end());

        while (l<=r){
            int mid=(l+r)/2;
            if (check(mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};