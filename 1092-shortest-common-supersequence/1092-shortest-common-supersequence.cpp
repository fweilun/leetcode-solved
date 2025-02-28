class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        if (str1.size() < str2.size()){
            swap(str1, str2);
        }
        //x: m, y:n
        int n=str1.size(), m=str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int y=0;y<n;y++){
            for (int x=0;x<m;x++){
                if (str1[y]==str2[x]){
                    dp[x+1][y+1]=dp[x][y]+1;
                }else{
                    dp[x+1][y+1]=max(dp[x][y+1],dp[x+1][y]);
                }
            }
        }
        int x=m-1, y=n-1;
        string out="";

        while(x>=0&&y>=0){
            if (str2[x]!=str1[y]){
                // check which is max and switch
                if (x>=0&&dp[x][y+1]==dp[x+1][y+1]){
                    out.push_back(str2[x]);
                    x--;
                } else if (y>=0&&dp[x+1][y]==dp[x+1][y+1]){
                    out.push_back(str1[y]);
                    y--;
                }
            }else{
                out.push_back(str1[y]);
                x--;
                y--;
            }
        }
        while (x>=0){
            out.push_back(str2[x]);
            x--;
        }
        while(y>=0){
            out.push_back(str1[y]);
            y--;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};