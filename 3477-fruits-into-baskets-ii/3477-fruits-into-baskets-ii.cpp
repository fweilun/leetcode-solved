class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        int m=fruits.size();
        vector<int> vis(baskets.size(), 0);
        for (int &f:fruits){
            for (int i=0;i<n;i++){
                 if (baskets[i]>=f&&!vis[i]){
                     m--;
                     vis[i]=true;
                     break;
                 }
            }
        }
        return m;
    }
};