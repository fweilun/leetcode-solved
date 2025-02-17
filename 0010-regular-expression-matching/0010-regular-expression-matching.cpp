class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(p.length() + 1, vector<bool>(s.length() + 1, false));

for (int i = 0; i <= p.length(); i++) {
	for (int j = 0; j <= s.length(); j++) {

		if (i == 0 and j == 0) {
			dp[i][j] = true;

		}
		else if (i == 0) {
			dp[i][j] = false;

		}
		else if (j == 0) {
			char ch = p[i - 1];

			if (ch == '*') {
				dp[i][j] = dp[i - 2][j];
			}

		}
		else {
			char ch = p[i - 1];
			char ch1 = s[j - 1];

			if (ch == '*') {
				dp[i][j] = dp[i - 2][j];
				char ch2 = p[i - 2];
				if (ch2 == '.' or ch2 == ch1) {
					dp[i][j] = dp[i][j] or dp[i][j - 1];
				}
			}
			else if (ch == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (ch == ch1) {
				dp[i][j] = dp[i - 1][j - 1];

			}
			else {
				dp[i][j] = false;
			}
		}
	}
}

return dp[p.length()][s.length()];
    }
};