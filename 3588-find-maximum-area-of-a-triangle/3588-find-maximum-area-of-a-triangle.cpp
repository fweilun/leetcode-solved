class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int maxx=-1, minx=INT_MAX, maxy=-1, miny=INT_MAX;
        using pii=pair<int, int>;
        long long maxArea=0;
        unordered_map<int, pii> bound_y; // x -> maxlen
        unordered_map<int, pii> bound_x; // y -> maxlen
        // need x -> maxHeight and y -> maxWidth
        for (vector<int>& coord:coords){
            int x=coord[0], y=coord[1];
            // 1. update boundx boundy
            if (bound_y.find(x)==bound_y.end()){
                bound_y[x] = {y,y};
            }else{
                bound_y[x].first = min(bound_y[x].first, y);
                bound_y[x].second = max(bound_y[x].second, y);
            }
            if (bound_x.find(y)==bound_x.end()){
                bound_x[y] = {x,x};
            }else{
                bound_x[y].first = min(bound_x[y].first, x);
                bound_x[y].second = max(bound_x[y].second, x);
            }
            // 2. update min, max x, y
            if (x>maxx) maxx=x;
            if (x<minx) minx=x;

            if (y>maxy) maxy=y;
            if (y<miny) miny=y;
        }
        for (auto it: bound_x){
            // first: y, second: width
            int width = it.second.second-it.second.first;
            int height = max(it.first - miny,maxy - it.first);
            long long area = 1LL * width * height;
            if (area>maxArea){
                maxArea=area;
            }
        }
        for (auto it: bound_y){
            // first: y, second: width
            int width = it.second.second-it.second.first;
            int height = max(it.first - minx,maxx - it.first);
            long long area = 1LL * width * height;
            if (area>maxArea){
                maxArea=area;
            }
        }
        return maxArea==0?-1:maxArea;
    }
};