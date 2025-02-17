class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows==1) return s;
        string r;
        int n = s.size(), idx=0;
        int gap = 2*numRows-2;
        int offset;
        for (int i=0;i < numRows;i++, idx=i, offset=gap-2*i){
            while (idx < n){
                r+=s[idx];
                if (idx%(numRows-1) && idx+offset < n){
                    r+=s[idx+offset];
                }
                idx+=gap;
            }
        }
        return r;
    }
};