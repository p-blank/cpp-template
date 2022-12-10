// 0 base indexed LCA

struct LCA {
    vector<int> path, in, logs;
    vector<vector<int> > table;
    vector<bool> vis;
    int n; 

    LCA(vector<vector<int>> &v, int root = 0) {
        n = v.size();
        in.resize(n);
        path.reserve(n * 2);
        vis.assign(n, 0);
        dfs(v, root);
        n = path.size();
        logs.resize(n);
        table.resize(21, vector<int> (n, 0));
        build();
    }

    void dfs(vector<vector<int>> &v, int s) {
        vis[s] = 1;
        in[s] = path.size();
        path.push_back(s);
        for (auto i : v[s]) if (!vis[i]) {
            dfs(v, i);
            path.push_back(s);
        }
    }

    void build() {
        for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
        for (int i = 0; i <= logs[n]; i++) {
            int curLen = 1 << i; // 2^i
            for (int j = 0; j + curLen <= n; j++)
                if (curLen == 1) table[i][j] = path[j];
                else table[i][j] = min(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
        }
    }

    int query(int l, int r) {
        int p = logs[r - l + 1];
        int pLen = 1 << p; // 2^p
        return min(table[p][l], table[p][r - pLen + 1]);
    }

    int lca(int u, int v) {
        int left = in[u], right = in[v];
        if (left > right) swap(left, right);
        return query(left, right);
    }
};