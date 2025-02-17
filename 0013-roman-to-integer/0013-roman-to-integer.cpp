class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int r{0};
        int last = 9999;

        for (char &x :s){
            if (m[x] > last){
                r -= last;
                r += (m[x] - last);
                continue;
            }

            r += m[x];
            last = m[x];
        }
        return r;
    }
};