class Solution {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;
    long long combination(int n, int k) {
        if (k == 0 || k == n) return 1;
        if (table[n][k] != -1) return table[n][k];
        return table[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long leftWays = solve(left) % MOD;
        long long rightWays = solve(right) % MOD;
        long long ways = combination(left.size() + right.size(), left.size());
        ways = (ways * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table = vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1));
        return (solve(nums) - 1 + MOD) % MOD;
    }
};