class Solution {
public:
    bool isValid(string s) {
        std::map<char, int> mapping = {
            {'(', 1}, {')', -1}, 
            {'[', 2}, {']', -2}, 
            {'{', 3}, {'}', -3}
        };
        stack<int> stk;
        for (char c:s){
            if (stk.size() == 0){
                stk.push(mapping[c]);
                continue;
            }

            bool match = !(stk.top() + mapping[c]);
            if (stk.top() > 0 && mapping[c] < 0){
                if (match){
                    stk.pop();
                    continue;
                }
                // not match and one left on right
                return false;
            }
            stk.push(mapping[c]);
        }
        return stk.size() == 0;

    }
};