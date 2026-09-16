class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long N = n + k - 1;
        long long K = 2 * k;
        if (K > N) return 0;
        long long num = 1, den = 1;
        for (long long i = 1; i <= K; ++i) {
            num = (num * (N - K + i)) % MOD;
            den = (den * i) % MOD;
        }
        long long inv_den = power(den, MOD - 2, MOD);
        return (num * inv_den) % MOD;
    }

private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};