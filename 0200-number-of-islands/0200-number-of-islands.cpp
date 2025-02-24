class Solution {
public:
    int n,m;
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& grid, int x, int y){
        if (x<0||x>=n||y<0||y>=m || vis[x][y]) return false;
        vis[x][y]=true;
        if (grid[x][y]=='0') return false;
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        n=grid.size();m=grid[0].size();
        vis=vector<vector<bool>>(n, vector<bool>(m, false));
        for (int x=0;x<n;x++){
            for (int y=0;y<m;y++){
                cnt+=dfs(grid, x, y);
            }
        }
        return cnt;
    }
};