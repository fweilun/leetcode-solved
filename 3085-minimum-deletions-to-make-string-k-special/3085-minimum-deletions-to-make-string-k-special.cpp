class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int freq_tot=word.size();
        for (char&x:word){
            ++freq[x-'a'];
        }
        int l=0, r=word.size()-1, mid;
        sort(freq.begin(), freq.end());

        int prev=0, post=0;
        int delcnt=0,min_delcnt=INT_MAX;
        for (int i=0;i<26;i++){
            if (!freq[i]) continue;
            post=0;
            for (int j=i+1;j<26;j++){
                post += max(freq[j]-freq[i]-k, 0);
            }
            delcnt = prev+post;
            if (delcnt < min_delcnt){
                min_delcnt = delcnt;
            }
            prev+=freq[i];
        }
        return min_delcnt;
    }
};
// aaaabbc
// 1 2 4

// a bb ccc ddddd
// 1 2 3 5
