class Solution {
public:
    int rob(vector<int>& nums) {
       int old_rob=0, old_nrob=0, old_nnrob=0;
       int rob, nrob, nnrob;
       for (int &x: nums){
            nrob = old_rob;
            rob = max(old_nrob, old_nnrob) + x;
            nnrob = old_nrob;
            // restore the value
            old_rob = rob;
            old_nrob = nrob;
            old_nnrob = nnrob;
       }
       return max(rob, nrob);
    }
};


//  2 * n
// dp(i: idx, j: true | false) := maximal value up to idx.
// dp(0, j) = dp(1, j-1)
// dp(1, j) = max(dp(0, j-1), dp(0, j-2)) + v(j)

// 1 2 3 1
// 1 2 4 3
// 0 1 2 4