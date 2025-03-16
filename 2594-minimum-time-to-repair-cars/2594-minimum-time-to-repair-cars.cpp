class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        auto check=[&](long long max_time){
            int to_fix=cars;
            for (int i=0;i<n;i++){
                to_fix-=int(sqrt(max_time/ranks[i]));
                if (to_fix<=0) return true;
            }
            return false;
        };
        int mini=*min_element(ranks.begin(), ranks.end());
        long long l=1, r=mini*cars, mid=0;
        r*=cars;
        while (l<=r){
            mid=(l+r)/2;
            if (check(mid)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};