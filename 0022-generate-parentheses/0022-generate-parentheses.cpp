class Solution {
public:
    void gen(string s, int left, int right, vector<string> &result){
        if (!left) {
            while (right--){
                s = s + string(")");
            }
            result.push_back(s);
            return;
        }
        if (!right) {
            return;
        }


        if ((s.size() == 0 || left >= right) ){
            gen(s + string("("), left-1,right, result);
        }else{
            gen(s + string("("), left-1,right, result);
            gen(s + string(")"), left,right-1, result);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        int left{n}, right{n};
        vector<string> result;
        gen(s, left, right, result);
        return result;
    }
};