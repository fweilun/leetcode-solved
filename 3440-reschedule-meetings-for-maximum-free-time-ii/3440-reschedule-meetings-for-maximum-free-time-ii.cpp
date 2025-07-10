class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> time_chunk;
        int n = startTime.size();
        vector<int> free_space;
        for (int i=0;i<=n;++i){
            if (!i){
                time_chunk.push_back(startTime[0]);
                free_space.push_back(startTime[0]);
            }else if (i==n){
                time_chunk.push_back(endTime[n-1]-startTime[n-1]);
                time_chunk.push_back(eventTime-endTime[n-1]);
                free_space.push_back(eventTime-endTime[n-1]);
            }else{
                time_chunk.push_back(endTime[i-1]-startTime[i-1]);
                time_chunk.push_back(startTime[i]-endTime[i-1]);
                free_space.push_back(startTime[i]-endTime[i-1]);
            }
        }
        int m=time_chunk.size();
        sort(free_space.begin(), free_space.end());
        int max_tot=0, tot=0;
        for (int i=1;i<m;i+=2){
            auto it = lower_bound(free_space.begin(), free_space.end(), time_chunk[i]);
            tot = time_chunk[i-1]+time_chunk[i+1];
            if (it != free_space.end()) {
                int require_space = *it;
                int cnt = (time_chunk[i-1] >= require_space) + (time_chunk[i+1] >= require_space);
                if (free_space.end() - it > cnt){
                    tot += time_chunk[i];
                }
            }
            max_tot = max(max_tot, tot);
        }
        return max_tot;
    }
};