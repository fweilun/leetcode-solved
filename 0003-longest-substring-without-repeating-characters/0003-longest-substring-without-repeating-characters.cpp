class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max_size = 0;
        std::unordered_set<char> window;
        std::queue<char> store;
        for (int i = 0;i < n;i++){
            if (window.find(s[i]) != window.end()){
                max_size = max((int)window.size(), max_size);
                while (store.front() != s[i]) {
                    window.erase(store.front());
                    store.pop();
                }
                store.pop();
            }
            store.push(s[i]);
            window.insert(s[i]);
        }
        max_size = max((int)window.size(), max_size);
        return max_size;
    }
};