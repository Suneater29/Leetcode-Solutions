class Solution {
    struct Node {
        int prod;
        int cnt[5];
        Node() {
            prod = 1;
            for (int i = 0; i < 5; ++i) cnt[i] = 0;
        }
    };

    int n, K;
    vector<Node> tree;
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.prod = (left.prod * right.prod) % K;
        for (int i = 0; i < K; ++i) {
            parent.cnt[i] = left.cnt[i];
        }
        for (int i = 0; i < K; ++i) {
            int new_rem = (left.prod * i) % K;
            parent.cnt[new_rem] += right.cnt[i];
        }
        return parent;
    }

    void build(int node, int start, int end, const vector<int>& nums) {
        if (start == end) {
            int val = nums[start] % K;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, nums);
        build(2 * node + 1, mid + 1, end, nums);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % K;
            tree[node] = Node();
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        if (r <= mid) {
            return query(2 * node, start, mid, l, r);
        }
        if (l > mid) {
            return query(2 * node + 1, mid + 1, end, l, r);
        }
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
        vector<int> result;
        result.reserve(queries.size());
        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            update(1, 0, n - 1, idx, val);
            Node resNode = query(1, 0, n - 1, start, n - 1);
            result.push_back(resNode.cnt[x]);
        }
        return result;
    }
};