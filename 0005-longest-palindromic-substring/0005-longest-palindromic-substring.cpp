class Solution {
public:
    pair<int, int> solve(string &s, int left, int right){
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return {left+1,right-1};
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int max_count = 0;
        pair<int, int> tmp;

        for (int pivot = 0;pivot < n - 1;pivot++){
            pair<int, int> r1 = solve(s, pivot, pivot);
            int n1 = r1.second - r1.first + 1;
            pair<int, int> r2 = solve(s, pivot, pivot + 1);
            int n2 = r2.second - r2.first + 1;
            if (n1 > max_count){
                max_count = n1;
                tmp = r1;
            }
            if (n2 > max_count){
                max_count = n2;
                tmp = r2;
            }
        }

        
        // cout << max_count << endl;
        return string(s.begin()+tmp.first, s.begin()+tmp.second+1);
    }
};