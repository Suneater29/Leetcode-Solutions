#include <vector>

class Solution {
public:
    vector<long long> resultArray(std::vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            std::vector<long long> next_dp(k, 0);
            int current_rem = num % k;
            next_dp[current_rem]++;
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * current_rem) % k;
                    next_dp[new_rem] += dp[r];
                }
            }
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }
            dp = std::move(next_dp);
        }
        return result;
    }
};