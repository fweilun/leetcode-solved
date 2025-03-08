class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt=0, mini=INT_MAX;
        int l=0, r=0, n=blocks.size();
        if (!n) return 0;
        for (;r<n;r++){
            cnt+=(blocks[r]=='W');
            if (r-l+1==k){
                mini=min(mini, cnt);
                cnt-=(blocks[l++]=='W');
            }
        }
        return mini;
    }
};