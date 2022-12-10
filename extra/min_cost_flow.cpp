struct edge{
    int a, b, cap, cost;
};

vector<vector<int>> adj, cost, cap;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, inf);
    d[v0] = 0;
    vector<bool> inq(n, 0);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while(q.size()) {
        auto u = q.front();
        q.pop();
        inq[u] = 0;
        for(auto v : adj[u]) {
            if (cap[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<edge> edg, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    cap.assign(N, vector<int>(N, 0));
    for(edge e : edg) {
        adj[e.a].push_back(e.b);
        adj[e.b].push_back(e.a);
        cost[e.a][e.b] = e.cost;
        cost[e.b][e.a] = -e.cost;
        cap[e.a][e.b] = e.cap;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while(flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == inf) break;
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, cap[p[cur]][cur]);
            cur = p[cur];
        }
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            cap[p[cur]][cur] -= f;
            cap[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if(flow < K) return -1;
    else return cost;
}