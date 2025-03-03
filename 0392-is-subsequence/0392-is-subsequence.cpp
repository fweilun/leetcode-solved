class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(int si=0,ti=0;ti<=t.size()&&si<s.size();ti++) {if (ti==t.size()&&si!=s.size()) return false; else si+=(s[si]==t[ti]);}
        return true;
    }
};