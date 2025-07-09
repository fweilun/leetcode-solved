class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        queue<int> freeTime;
        int n=startTime.size();
        int tot=0, max_tot=0;
        for (int i=0;i<=n;++i){
            int temp;
            if (i==0) temp = startTime[0];
            else if (i==n) temp = eventTime-endTime[n-1];
            else temp = startTime[i] - endTime[i-1];
            tot+=temp;
            freeTime.push(temp);
            if (freeTime.size()>k+1){
                tot-=freeTime.front();
                freeTime.pop();
            }
            max_tot = max(tot, max_tot);
        }
        return max_tot;
    }
};