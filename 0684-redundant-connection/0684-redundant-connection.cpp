class Solution {
public:
    vector<int> parent;
    int find(const int &x){
        // compression
        if (parent[x]!=x) {
            parent[x] = find(parent[x]);
            return parent[x];
        }
        return x;
    }
    void unite(const int &x, const int &y) {
        int root_of_x = find(x);
        int temp=y, store;
        while (parent[temp] != temp) {
            store = parent[temp];
            parent[temp]=root_of_x;
            temp = store;
        }
        parent[temp] = root_of_x;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent = vector<int>(n+1, 0);
        for (int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<int> out;
        for (const vector<int>& e:edges) {
            if (find(e[0]) != find(e[1])){
                unite(e[0], e[1]);
            }else{
                out=e;
            }
        }
        return out;
    }
};