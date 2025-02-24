class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, ans = 0, maxFreq = 0, mp[26] = {0};
        for (int j = 0; j < s.size(); j++) {
            maxFreq = max(maxFreq, ++mp[s[j] - 'A']);
            if ((j - i + 1) - maxFreq > k) mp[s[i++] - 'A']--;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};