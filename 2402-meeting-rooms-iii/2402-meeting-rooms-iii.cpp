class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[0] < v2[0];
        });

        using pii = pair<long long, int>; // (endTime, room idx)
        priority_queue<pii, vector<pii>, greater<>> occ;
        priority_queue<int, vector<int>, greater<>> available; // just store room idx
        vector<int> record(n, 0);

        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        for (const auto& meet : meetings) {
            long long start = meet[0], end = meet[1];

            // Release occupied rooms
            while (!occ.empty() && occ.top().first <= start) {
                available.push(occ.top().second);
                occ.pop();
            }

            int room = -1;
            long long actual_start = start;

            if (!available.empty()) {
                room = available.top();
                available.pop();
            } else {
                // Wait for earliest room
                auto [finish, idx] = occ.top(); occ.pop();
                room = idx;
                actual_start = finish;
            }

            ++record[room];
            occ.push({actual_start + (end - start), room});
        }

        // find the most used room
        int max_use = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (record[i] > max_use) {
                max_use = record[i];
                ans = i;
            }
        }

        return ans;
    }
};