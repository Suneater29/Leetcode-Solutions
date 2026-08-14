class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int len;
        int prefix, suffix, best;
        Node() {
            leftChar = rightChar = '#';
            len = prefix = suffix = best = 0;
        }
        Node(char c) {
            leftChar = rightChar = c;
            len = prefix = suffix = best = 1;
        }
    };

    vector<Node> seg;
    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.best = max(a.best, b.best);
        res.prefix = a.prefix;
        if (a.prefix == a.len && a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }
        res.suffix = b.suffix;
        if (b.suffix == b.len && a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }
        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, char ch) {
        if (l == r) {
            seg[node] = Node(ch);
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, ch);
        else
            update(2 * node + 1, mid + 1, r, pos, ch);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        seg.resize(4*n);
        build(1, 0, n - 1, s);
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(seg[1].best);
        }
        return ans;
    }
};