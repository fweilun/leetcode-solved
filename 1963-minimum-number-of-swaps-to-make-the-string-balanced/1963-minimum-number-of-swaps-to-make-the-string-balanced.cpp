class Solution {
public:
    int minSwaps(string s) {
        int out=0;
        for (char &c:s) {
            if (c == '[') out++;
            else if (out) out--;
        }
        return (out+1)/2;
    }
};
