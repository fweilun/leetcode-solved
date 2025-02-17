class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int tot=n*m;
        vector<int> out(tot, 0);
        
        int y=-1, x=0, idx=0;
        n-=1;
        while (idx < tot){
            for (int i = 0;i < m;i++){
                if (idx == tot) break;
                out[idx++] = matrix[x][++y];
            }
            m--;
            for (int i = 0;i < n;i++){
                if (idx == tot) break;
                out[idx++] = matrix[++x][y];
            }
            n--;
            for (int i = 0;i < m;i++){
                if (idx == tot) break;
                out[idx++] = matrix[x][--y];
            }
            m--;
            for (int i = 0;i < n;i++){
                if (idx == tot) break;
                out[idx++] = matrix[--x][y];
            }
            n--;
        }
        return out;
    }
};