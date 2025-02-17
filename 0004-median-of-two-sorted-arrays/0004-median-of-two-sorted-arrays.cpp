class Solution {
public:
    /* Test case: [1, 3] and [2, 5, 8]; n1=2 n2=3 
    1st iteration
      1 | 3
    2 5 | 8
	5<=3 is false so moving towards right half in nums1
    
    2nd iteration
    1 3 | -          
      2 | 5  8
    return max(3, 2)
	
    1 2 3 5 8; median=3
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n2 < n1) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int s = 0;
        int e = n1;
        int midInMergedArr = (n1+n2+1)/2; //3
        
        int cut1, cut2, l1, l2, r1, r2;
        
        while(s<=e) {
            cut1 = s+(e-s)/2; //1  //2
            cut2 = midInMergedArr - cut1; //2 //1
            
            l1 = (cut1==0) ? INT_MIN : nums1[cut1-1];
            l2 = (cut2==0) ? INT_MIN : nums2[cut2-1];
            
            r1 = (cut1>=n1) ? INT_MAX : nums1[cut1];
            r2 = (cut2>=n2) ? INT_MAX : nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                if((n1+n2)%2 == 0) {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
                else
                    return (max(l1, l2));
            }
            else
                if(r1 < l2) { //move right in nums1
                    s = cut1+1;
                }
            else
                if(r2 < l1) { // move left in nums1
                    e = cut1-1;   
                }
        }
        return 0.0;
    }
};