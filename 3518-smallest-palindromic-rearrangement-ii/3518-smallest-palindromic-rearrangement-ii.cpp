class Solution {
public:
    const long long LIM = 1000000LL + 1;

    vector<int> primes;

    void sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i <= n; i++) {
            if (!isPrime[i]) continue;
            primes.push_back(i);
            if (1LL * i * i <= n)
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
        }
    }

    int exponentInFact(int n, int p) {
        int e = 0;
        while (n) {
            n /= p;
            e += n;
        }
        return e;
    }

    long long powerCap(long long a, int e) {
        long long res = 1;
        while (e) {
            if (e & 1) {
                res *= a;
                if (res >= LIM) return LIM;
            }
            e >>= 1;
            if (e) {
                a *= a;
                if (a >= LIM) a = LIM;
            }
        }
        return min(res, LIM);
    }

    long long countWays(vector<int>& cnt) {
        int len = 0;
        for (int x : cnt) len += x;

        long long ans = 1;

        for (int p : primes) {
            if (p > len) break;

            int e = exponentInFact(len, p);

            for (int x : cnt)
                e -= exponentInFact(x, p);

            if (e) {
                ans *= powerCap(p, e);
                if (ans >= LIM) return LIM;
            }
        }

        return min(ans, LIM);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            halfLen += half[i];

            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        sieve(halfLen);

        if (countWays(half) < k)
            return "";

        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};