#include <vector>
#include <string>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    vector<int> subtree_size;
    vector<int> tree;
    string node_str;
    int cur_pos;

    // First DFS to compute subtree sizes, depths, parents, and heavy children
    int dfs(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        subtree_size[u] = 1;
        int max_sub = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int sub = dfs(v, u, d + 1);
                subtree_size[u] += sub;
                if (sub > max_sub) {
                    max_sub = sub;
                    heavy[u] = v;
                }
            }
        }
        return subtree_size[u];
    }

    // Second DFS to set up heavy-light chains and positions
    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    // Segment Tree functions
    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    // Query path between u and v
    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                res ^= query_tree(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            } else {
                res ^= query_tree(1, 0, n - 1, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res ^= query_tree(1, 0, n - 1, pos[v], pos[u]);
        } else {
            res ^= query_tree(1, 0, n - 1, pos[u], pos[v]);
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        node_str = s;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree_size.assign(n, 0);
        cur_pos = 0;

        dfs(0, -1, 0);
        decompose(0, 0);

        tree.assign(4 * n, 0);
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            update_tree(1, 0, n - 1, pos[i], mask);
        }

        vector<bool> answer;
        for (const auto& q : queries) {
            if (q[0] == 'u') { // update u c
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();
                node_str[u] = c;
                int mask = 1 << (c - 'a');
                update_tree(1, 0, n - 1, pos[u], mask);
            } else { // query u v
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));
                
                int path_mask = query_path(u, v);
                // Check if path_mask has at most one bit set
                bool is_palindrome = (path_mask & (path_mask - 1)) == 0;
                answer.push_back(is_palindrome);
            }
        }

        vector<string> dummy_queries;
        return answer;
    }
};