class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int m=meetings.size();
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
        });
        int e=0, out=0;
        for (vector<int>& meet:meetings){
            if (meet[0]>e){
                out+=(meet[0]-e-1);
            }
            e=max(e, meet[1]);
        }
        return out+(days-e);
    }
};