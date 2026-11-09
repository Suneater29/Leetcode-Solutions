#include <vector>
#include <queue>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<long long, int>,vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
        
        set<int> availableServers;
        for (int i = 0; i < k; ++i) {
            availableServers.insert(i);
        }
        vector<int> requestCount(k, 0);
        int maxRequests = 0;
        for (int i = 0; i < arrival.size(); ++i) {
            long long currTime = arrival[i];
            long long duration = load[i];
            while (!busyServers.empty() && busyServers.top().first <= currTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            if (availableServers.empty()) {
                continue;
            }
            auto it = availableServers.lower_bound(i % k);
            if (it == availableServers.end()) {
                it = availableServers.begin(); 
            }
            int serverId = *it;
            availableServers.erase(it);
            busyServers.push({currTime + duration, serverId});
            requestCount[serverId]++;
            maxRequests = max(maxRequests, requestCount[serverId]);
        }
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            if (requestCount[i] == maxRequests) {
                result.push_back(i);
            }
        }
        return result;
    }
};