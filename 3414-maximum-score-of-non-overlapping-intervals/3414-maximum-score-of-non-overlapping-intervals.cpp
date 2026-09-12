#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            if (l != other.l) return l < other.l;
            if (r != other.r) return r < other.r;
            return id < other.id;
        }
    };

    struct DPState {
        long long weight = 0;
        vector<int> indices;

        bool operator<(const DPState& other) const {
            if (weight != other.weight) {
                return weight < other.weight; // Prioritize higher weight
            }
            // For equal weight, prioritize lexicographically smaller list of indices
            return indices > other.indices;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> sorted_intervals(n);
        for (int i = 0; i < n; ++i) {
            sorted_intervals[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(sorted_intervals.begin(), sorted_intervals.end());
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = sorted_intervals[i].l;
        }
        vector<vector<DPState>> dp(n + 1, vector<DPState>(5));
        for (int i = n - 1; i >= 0; --i) {
            int next_idx = upper_bound(starts.begin() + i + 1, starts.end(), sorted_intervals[i].r) - starts.begin();
            for (int k = 1; k <= 4; ++k) {
                DPState best = dp[i + 1][k];
                DPState take;
                take.weight = sorted_intervals[i].weight + dp[next_idx][k - 1].weight;
                take.indices = {sorted_intervals[i].id};
                for (int idx : dp[next_idx][k - 1].indices) {
                    take.indices.push_back(idx);
                }
                sort(take.indices.begin(), take.indices.end());
                if (best < take) best=take;
                dp[i][k] = best;
            }
        }
        return dp[0][4].indices;
    }
};