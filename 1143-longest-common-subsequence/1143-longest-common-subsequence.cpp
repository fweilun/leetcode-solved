class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() < text2.size()) swap(text1, text2);
        int n = text1.size();
        int m = text2.size();
        
        vector<int> arr(m + 1, 0);
        int upl{0};
        for (int i = 0;i < n;i++){
            upl = 0;
            for (int j = 0;j < m;j++){
                int now = arr[j+1];
                if (text1[i] == text2[j]){
                    arr[j+1] = upl + 1;
                }else{
                    arr[j+1] = max(arr[j+1], arr[j]);
                }
                upl = now;
                // cout << arr[j+1] << " ";
            }
            // cout << endl;
        }
        return arr[arr.size()-1];
        

        
    }
};