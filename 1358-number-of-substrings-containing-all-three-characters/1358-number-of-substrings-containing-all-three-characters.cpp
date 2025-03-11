class Solution {
public:
    bool check(vector<int>&v){
        return v[0]&&v[1]&&v[2];
    }
    int numberOfSubstrings(string s) {
        int n=s.size(), out=0;
        vector<int> freq=vector<int>(3, 0);
        for (int l=0, r=0; r<=n;){
            while(r<n&&!check(freq)){
                freq[s[r]-'a']++;
                r++;
            }
            if (check(freq)){
                freq[s[l++]-'a']--;
                out+=(n-r+1);
            }
            if (r==n&&!check(freq)) break;
        }
        return out;
    }
};