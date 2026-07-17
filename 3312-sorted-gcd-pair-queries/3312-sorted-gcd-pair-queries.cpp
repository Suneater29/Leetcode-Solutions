class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // divisible[i] = numbers divisible by i
        vector<long long> divisible(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i)
                divisible[i] += freq[j];
        }

        // exact gcd counts
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long cnt = divisible[g];
            exact[g] = cnt * (cnt - 1) / 2;

            for (int mult = g + g; mult <= mx; mult += g)
                exact[g] -= exact[mult];
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exact[i];

        vector<int> ans;

        for (long long k : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), k + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};