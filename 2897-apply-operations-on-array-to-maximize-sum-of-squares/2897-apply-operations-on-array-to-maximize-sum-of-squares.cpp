class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        std::vector<int> bitCount(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((num >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }
        long long totalSum = 0;
        long long MOD = 1e9 + 7;
        for (int i = 0; i < k; ++i) {
            long long currentNum = 0;
            for (int bit = 31; bit >= 0; --bit) {
                if (bitCount[bit] > 0) {
                    currentNum |= (1LL << bit);
                    bitCount[bit]--;
                }
            }
            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }
        return totalSum;
    }
};