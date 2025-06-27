class Solution {
public:
    bool repeatK(string &s, string &t, int k){
        int n=s.size(), m=t.size();
        int idx=0, idxt=0;
        while (k--){
            idxt=0;
            while (idx<n && idxt<m){
                if (s[idx]==t[idxt]){
                    ++idx;
                    ++idxt;
                }else{
                    ++idx;
                }
            }
            if (idxt<m) return false;
        }
        return true;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> store;
        store.push("");
        int maxsize=s.size()/k;
        string ans="";
        while (!store.empty()){
            string temp = store.front(); store.pop();
            for (char c='a'; c <= 'z'; ++c){
                string next = temp + c;
                if (next.size() > maxsize)  continue;
                if (!repeatK(s, next, k)) continue;
                store.push(next);
                ans = next;
            }
        }
        return ans;
    }
};