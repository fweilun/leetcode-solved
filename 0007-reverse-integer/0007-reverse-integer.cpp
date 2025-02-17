class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);
        long resultnum = (num[0] == '-') ? 1:-1;
        string result(num.begin()+(resultnum+1)/2, num.end());
        ::reverse(result.begin(), result.end());
        long ans = resultnum * -1 * stol(result);
        if (ans != (int)ans)
            return 0;
        return ans;
    }
};