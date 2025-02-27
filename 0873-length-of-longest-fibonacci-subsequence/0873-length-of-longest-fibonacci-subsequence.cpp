class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(), maxi=0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for (int j=2;j<n;j++){
            int s=0, e=j-1;
            while(s<e){
                int sum=arr[s]+arr[e];
                if (arr[s]+arr[e]>arr[j]){
                    e--;
                }else if (arr[s]+arr[e]<arr[j]){
                    s++;
                }else{
                    dp[e][j]=max(dp[e][j], dp[s][e]+1);
                    maxi=max(maxi, dp[e][j]);
                    s++;
                    e--;
                }   
            }
        }
        return maxi;
    }
};