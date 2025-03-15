class Solution {
public:

    vector<int> closestPrimes(int left, int right) {
        int isPrime[1000001];
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i=2;i<=500000;i++){
            if (isPrime[i]){
                for (int j=2*i;j<=1000000;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int> out={-1,-1};
        int rcd=0;
        for (int idx=left;idx<=right;idx++){
            if (isPrime[idx]){
                if (rcd>0 && (idx-rcd<out[1]-out[0]||out[0]==-1)){
                    out[1]=idx;
                    out[0]=rcd;
                }
                rcd=idx;
            }
        }
        return out;
    }
};