class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0, e=height.size()-1, maxi=0;;
        while(s<e){
            maxi=max(maxi, min(height[s], height[e])*(e-s));
            if (height[s]>=height[e]){
                e--;
            }else{
                s++;
            }
        }
        return maxi;
    }
};