class Solution {
public:
    string makeFancyString(string s) {
        string out;
        int counter = 0;
        char last = '@';
        for (char&c: s){
            if (c==last){
                ++counter;
            }else{
                last = c;
                counter = 1;
            }
            if (counter>=3) continue;
            out.push_back(c);
        }
        return out;
    }
};