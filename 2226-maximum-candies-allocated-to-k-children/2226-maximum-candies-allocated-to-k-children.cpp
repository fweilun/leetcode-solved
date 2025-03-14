class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        auto check=[&](long long n){
            // k people, n each
            long long people=k;
            for (int &x:candies){
                people-=x/n;
                if (people<=0) return true;
            }
            return false;
        };
        long long l=1, r=1e7, mid;
        while (l<=r){
            mid=(l+r)/2;
            if (check(mid)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l-1;
    }
};