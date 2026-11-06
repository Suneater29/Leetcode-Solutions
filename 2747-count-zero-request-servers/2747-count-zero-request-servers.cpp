#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
        int m = queries.size();
        std::vector<int> ans(m);
        std::vector<std::vector<int>> indexedQueries(m, std::vector<int>(2));
        for (int i = 0; i < m; ++i) {
            indexedQueries[i][0] = queries[i];
            indexedQueries[i][1] = i;
        }
        std::sort(indexedQueries.begin(), indexedQueries.end());
        std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        
        int left = 0, right = 0;
        int logCount = logs.size();
        std::unordered_map<int, int> serverFreq;
        
        for (int i = 0; i < m; ++i) {
            int qTime = indexedQueries[i][0];
            int originalIndex = indexedQueries[i][1];
            int windowStart = qTime - x;
            int windowEnd = qTime;
            while (right < logCount && logs[right][1] <= windowEnd) {
                serverFreq[logs[right][0]]++;
                right++;
            }
            while (left < logCount && logs[left][1] < windowStart) {
                serverFreq[logs[left][0]]--;
                if (serverFreq[logs[left][0]] == 0) {
                    serverFreq.erase(logs[left][0]);
                }
                left++;
            }
            ans[originalIndex] = n - serverFreq.size();
        }
        
        return ans;
    }
};