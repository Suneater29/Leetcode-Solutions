class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> window_cost(n - x + 1, 0);
        multiset<long long> left_half, right_half;
        long long left_sum = 0, right_sum = 0;
        auto balance = [&]() {
            while (left_half.size() > right_half.size() + 1) {
                auto it = prev(left_half.end());
                long long val = *it;
                left_half.erase(it);
                left_sum -= val;
                right_half.insert(val);
                right_sum += val;
            }
            while (left_half.size() < right_half.size()) {
                auto it = right_half.begin();
                long long val = *it;
                right_half.erase(it);
                right_sum -= val;
                left_half.insert(val);
                left_sum += val;
            }
        };
        auto add_element = [&](long long val) {
            if (left_half.empty() || val <= *left_half.rbegin()) {
                left_half.insert(val);
                left_sum += val;
            } else {
                right_half.insert(val);
                right_sum += val;
            }
            balance();
        };
        auto remove_element = [&](long long val) {
            auto it_left = left_half.find(val);
            if (it_left != left_half.end()) {
                left_sum -= val;
                left_half.erase(it_left);
            } else {
                auto it_right = right_half.find(val);
                if (it_right != right_half.end()) {
                    right_sum -= val;
                    right_half.erase(it_right);
                }
            }
            balance();
        };
        for (int i = 0; i < n; ++i) {
            add_element(nums[i]);
            if (i >= x) {
                remove_element(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *left_half.rbegin();
                long long cost = (left_half.size() * median - left_sum) + (right_sum - right_half.size() * median);
                window_cost[i - x + 1] = cost;
            }
        }
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0; 
        }
        for (int j = 1; j <= k; ++j) {
            for (int i = j * x; i <= n; ++i) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + window_cost[i - x]);
                }
            }
        }
        return dp[n][k];
    }
};