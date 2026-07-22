class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;

        vector<int> starts, ends, lengths;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                starts.push_back(i);
                ends.push_back(j - 1);
                lengths.push_back(j - i);
                i = j;
            } else {
                i++;
            }
        }

        int M = starts.size();
        vector<int> g;
        for (int k = 0; k + 1 < M; k++) g.push_back(lengths[k] + lengths[k + 1]);

        int gsz = g.size();
        vector<int> LOG(gsz + 1, 0);
        for (int x = 2; x <= gsz; x++) LOG[x] = LOG[x / 2] + 1;

        vector<vector<int>> st;
        if (gsz > 0) {
            st.push_back(g);
            int j = 1;
            while ((1 << j) <= gsz) {
                vector<int>& prev = st.back();
                int half = 1 << (j - 1);
                int sz = gsz - (1 << j) + 1;
                vector<int> cur(sz);
                for (int idx = 0; idx < sz; idx++)
                    cur[idx] = max(prev[idx], prev[idx + half]);
                st.push_back(cur);
                j++;
            }
        }

        auto queryMax = [&](int l, int r) -> int {
            if (l > r) return 0;
            int k = LOG[r - l + 1];
            return max(st[k][l], st[k][r - (1 << k) + 1]);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            if (M == 0) {
                ans.push_back(totalOnes);
                continue;
            }

            // first zero-run with end >= l  => bisect_left on ends
            int i0 = lower_bound(ends.begin(), ends.end(), l) - ends.begin();

            if (i0 == M || starts[i0] > r) {
                ans.push_back(totalOnes);
                continue;
            }

            // last zero-run with start <= r => bisect_right on starts, then -1
            int i1 = upper_bound(starts.begin(), starts.end(), r) - starts.begin() - 1;

            if (i1 == i0) {
                ans.push_back(totalOnes);
                continue;
            }

            int clip_i0 = min(ends[i0], r) - max(starts[i0], l) + 1;
            int clip_i1 = min(ends[i1], r) - max(starts[i1], l) + 1;

            int maxGain;
            if (i1 == i0 + 1) {
                maxGain = clip_i0 + clip_i1;
            } else {
                int cand1 = clip_i0 + lengths[i0 + 1];
                int cand2 = lengths[i1 - 1] + clip_i1;
                maxGain = max(cand1, cand2);
                if (i1 - i0 >= 3) {
                    int mid = queryMax(i0 + 1, i1 - 2);
                    maxGain = max(maxGain, mid);
                }
            }

            ans.push_back(totalOnes + maxGain);
        }

        return ans;
    }
};