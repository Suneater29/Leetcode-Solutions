class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
        using State = tuple<long long, int, int>;
        priority_queue<State,vector<State>,greater<State>> pq;
        dp[0][1] = 0;
        pq.push({0, 0, 1});
        while (!pq.empty()) {
            auto [cost, u, run] = pq.top();
            pq.pop();
            if (cost != dp[u][run]) continue;
            if (u == n - 1) return static_cast<int>(cost);
            for (auto &[v, w] : adj[u]) {
                int newRun;
                if (labels[u] == labels[v]) {
                    newRun = run + 1;
                    if (newRun > k) continue;
                } else {
                    newRun = 1;
                }
                long long newCost = cost + w;
                if (newCost < dp[v][newRun]) {
                    dp[v][newRun] = newCost;
                    pq.push({newCost, v, newRun});
                }
            }
        }
        return -1;
    }
};