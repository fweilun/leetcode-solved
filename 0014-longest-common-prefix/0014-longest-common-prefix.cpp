class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        int p = common.size();
        for (int i = 1;i < strs.size() && p >= 0;i++){
            int tmp = 0;
            while (tmp != strs[i].size() && strs[i][tmp] == common[tmp]){
                tmp++;
            }
            p = min(p, tmp);
        }
        return string(common.begin(), common.begin()+p);
        
    }
};