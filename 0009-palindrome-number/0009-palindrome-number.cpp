class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string w = to_string(x);
        int n = w.size();
        for (int i = 0;i < n/2+1;i++){
            if (w[i] != w[n-i-1]) return false;
        }
        return true;
    }
};