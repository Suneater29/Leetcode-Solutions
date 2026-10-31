class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;
        vector<vector<vector<pair<int, int>>>> go(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1})));
        auto get_jump = [&](int r, int c, int dir) {
            int cur_r = r, cur_c = c;
            int cur_dir = dir; 
            while (true) {
                int nr = cur_r + (cur_dir == 1 ? 1 : 0);
                int nc = cur_c + (cur_dir == 0 ? 1 : 0);
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    return make_pair(-1, -1); 
                }
                if (grid[nr][nc] == 0) {
                    return make_pair(nr, nc); 
                } else {
                    cur_dir = 1 - cur_dir;
                    cur_r = nr;
                    cur_c = nc;
                }
            }
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    go[i][j][0] = get_jump(i, j, 0); 
                    go[i][j][1] = get_jump(i, j, 1); 
                }
            }
        }
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;
                auto [nx0, ny0] = go[i][j][0];
                if (nx0 != -1 && ny0 != -1) {
                    dp[nx0][ny0] = (dp[nx0][ny0] + dp[i][j]) % MOD;
                }
                auto [nx1, ny1] = go[i][j][1];
                if (nx1 != -1 && ny1 != -1) {
                    dp[nx1][ny1] = (dp[nx1][ny1] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};