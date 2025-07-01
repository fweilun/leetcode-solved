class Solution {
public:
    vector<int> state; // 0:not vis, 1:traversing, 2:done
    bool dfs_cycle(int from ,vector<vector<int>>& edge){
        if (state[from]==2) return false;
        if (state[from]==1) return true;
        state[from]=1;
        for (int& to:edge[from]){
            if (dfs_cycle(to, edge)) return true;
        }
        state[from]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, vector<int>{});
        for (vector<int>& conn:prerequisites){
            edge[conn[1]].push_back(conn[0]);
        }

        state=vector<int>(numCourses, 0);
        for (int i=0;i<numCourses;++i){
            if (dfs_cycle(i, edge)) return false;
        }
        return true;
    }
};