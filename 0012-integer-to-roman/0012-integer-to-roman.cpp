class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50,
                             40,   10,  9,   5,   4,   1};
        vector<string> rome = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
        string result;
        int ss{0};
        while (num>0){
            if (num >= value[ss]){
                int d = num/value[ss];
                for (int i = 0;i < d;i++){
                    result.append(rome[ss]);
                }
                num = num % value[ss];
            }
            ss++;
        }
        return result;
    }
};