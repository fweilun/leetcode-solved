class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i]==' ')i++;
        int neg = (s[i] == '-');
        i += (s[i]=='+');
        long num = 0;
        for (i+=neg;i < s.size();i++){
            if (!isdigit(s[i])) break;
            num*=10;
            num+=(s[i]-'0');
            if (num > INT_MAX) break;
        }
        num *= (1-neg*2);
        if (num > INT_MAX){
            num = INT_MAX;
        }else if (num < INT_MIN){
            num = INT_MIN;
        }
        return num;
    }
};