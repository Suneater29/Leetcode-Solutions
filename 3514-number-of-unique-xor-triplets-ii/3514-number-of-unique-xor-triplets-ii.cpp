class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<int> values;
        vector<bool> seen(1501, false);
        for (int x : nums) {
            if (!seen[x]) {
                seen[x] = true;
                values.push_back(x);
            }
        }
        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;
        for (int take = 0; take < 3; take++) {
            for (int xr = 0; xr < MAXX; xr++) {

                if (!dp[take][xr]) continue;

                for (int val : values) {
                    dp[take + 1][xr ^ val] = true;
                }
            }
        }
        int ans = 0;
        for (bool ok : dp[3])
            ans += ok;
        return ans;
    }
};