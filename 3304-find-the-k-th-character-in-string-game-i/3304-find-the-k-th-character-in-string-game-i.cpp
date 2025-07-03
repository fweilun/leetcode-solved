class Solution {
public:
    int dfs(int k){
        if (k<=1) return 0;
        int n=1;
        while (n<k){
            n*=2;
        }
        n/=2;
        return dfs(k-n)+1;
    }
    char kthCharacter(int k) {
        return dfs(k)+'a';
    }
};