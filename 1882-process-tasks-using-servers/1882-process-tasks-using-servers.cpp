class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
        vector<int> ans(m);
        long long currentTime = 0;
        for (int j = 0; j < m; ++j) {
            currentTime = max(currentTime, (long long)j);
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();
                freeServers.push({weight, index});
            }
            if (freeServers.empty()) {
                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();
                currentTime = freeTime;
                freeServers.push({weight, index});
                while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {
                    auto [ft, w, idx] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({w, idx});
                }
            }
            auto [weight, index] = freeServers.top();
            freeServers.pop();
            ans[j] = index;
            busyServers.push({currentTime + tasks[j], weight, index});
        }

        return ans;
    }
};