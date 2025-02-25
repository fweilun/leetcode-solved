class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int x0=1, y0=1;
        for (int x=0;x<n;x++){
            if (!matrix[x][0]){
                x0=0;
                break;
            }
        }
        for (int y=0;y<m;y++){
            if (!matrix[0][y]){
                y0=0;
                break;
            }
        }
        for (int x=1;x<n;x++){
            for (int y=1;y<m;y++){
                if (!matrix[x][y]){
                    matrix[0][y]=0;
                    matrix[x][0]=0;
                }
            }
        }
        for (int x=1;x<n;x++){
            for (int y=1;y<m;y++){
                if (!matrix[0][y] || !matrix[x][0]){
                    matrix[x][y]=0;
                }
            }
        }
        for (int x=0;x<n;x++){
            if (!x0){
                matrix[x][0]=0;
            }
        }
        for (int y=0;y<m;y++){
            if (!y0){
                matrix[0][y]=0;
            }
        }
    }
};