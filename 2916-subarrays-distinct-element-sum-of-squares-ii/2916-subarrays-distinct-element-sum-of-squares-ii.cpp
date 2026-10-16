#include <vector>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum_sq;
        long long sum_c;
        long long lazy;
    };

    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy != 0) {
            long long v = tree[node].lazy;
            int mid = (l + r) / 2;
            int left = 2 * node;
            tree[left].sum_sq = (tree[left].sum_sq + 2 * v * tree[left].sum_c + v * v % MOD * (mid - l + 1)) % MOD;
            tree[left].sum_c = (tree[left].sum_c + v * (mid - l + 1)) % MOD;
            tree[left].lazy = (tree[left].lazy + v) % MOD;
            int right = 2 * node + 1;
            tree[right].sum_sq = (tree[right].sum_sq + 2 * v * tree[right].sum_c + v * v % MOD * (r - mid)) % MOD;
            tree[right].sum_c = (tree[right].sum_c + v * (r - mid)) % MOD;
            tree[right].lazy = (tree[right].lazy + v) % MOD;

            tree[node].lazy = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long v) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[node].sum_sq = (tree[node].sum_sq + 2 * v * tree[node].sum_c + v * v % MOD * (r - l + 1)) % MOD;
            tree[node].sum_c = (tree[node].sum_c + v * (r - l + 1)) % MOD;
            tree[node].lazy = (tree[node].lazy + v) % MOD;
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, v);
        update(2 * node + 1, mid + 1, r, ql, qr, v);
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
        tree[node].sum_c = (tree[2 * node].sum_c + tree[2 * node + 1].sum_c) % MOD;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node].sum_sq;
        push(node, l, r);
        int mid = (l + r) / 2;
        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr)) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, {0, 0, 0});
        unordered_map<int, int> last_seen;
        long long total_sum = 0;
        long long current_subarrays_sum_sq = 0;
        for (int i = 0; i < n; ++i) {
            int last = last_seen.count(nums[i]) ? last_seen[nums[i]] : -1;
            update(1, 0, n - 1, last + 1, i, 1);
            last_seen[nums[i]] = i;
            long long current_total = query(1, 0, n - 1, 0, i);
            total_sum = (total_sum + current_total) % MOD;
        }
        return total_sum;
    }
};