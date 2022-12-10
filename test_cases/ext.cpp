/*.........tank.jpg.........*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T> using pxx = pair<T, T>;
 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define UB upper_bound
#define LB lower_bound
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define MP make_pair
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define endl "\n"
 
const int N = 2e5 + 5;
const int inf = 2e9 + 9;
 
template <class E> struct csr {
    vector<int> st;
    vector<E> edlst;
    csr(int n, const vector<pair<int, E>>& edges)
        : st(n + 1), edlst(edges.size()) {
        for (auto e : edges) st[e.ff + 1]++;
        for (int i = 1; i <= n; i++) st[i] += st[i - 1];
        auto cnt = st;
        for (auto e : edges) edlst[cnt[e.ff]++] = e.ss;
    }
};
 
struct SCC {
    int _n;
    struct imply { int _b; };
    vector<pair<int, imply>> edges;
    SCC(int n) : _n(n) {}
    int num_vertices() { return _n; }
    void add_edge(int _a, int _b) { edges.push_back({_a, {_b}}); }
    pair<int, vector<int>> scc_ids() {
        auto g = csr<imply>(_n, edges);
        int now_ord = 0, gid = 0;
        vector<int> vis, low(_n), ord(_n, -1), ids(_n);
        vis.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            vis.pb(v);
            for (int i = g.st[v]; i < g.st[v + 1]; i++) {
                auto _b = g.edlst[i]._b;
                if (ord[_b] == -1) self(self, _b), low[v] = min(low[v], low[_b]);
                else low[v] = min(low[v], ord[_b]);
            }if (low[v] == ord[v]) {
                while (1) {
                    int u = vis.back();
                    vis.pop_back();
                    ord[u] = _n;
                    ids[u] = gid;
                    if (u == v) break;
                }gid++;
            }
        };
        for(int i = 0; i < _n; i++) if (ord[i] == -1) dfs(dfs, i);
        for(auto& x : ids) x = gid - 1 - x;
        return {gid, ids};
    }
    vector<vector<int>> scc() {
        auto ids = scc_ids();
        int gid = ids.ff;
        vector<int> hsh(gid);
        for (auto x : ids.ss) hsh[x]++;
        vector<vector<int>> comp(ids.ff);
        for (int i = 0; i < gid; i++) comp[i].reserve(hsh[i]);
        for (int i = 0; i < _n; i++) comp[ids.ss[i]].pb(i);
        return comp;
    }
};
 
struct two_sat {
    int _n;
    vector<bool> _res;
    SCC scc;
    two_sat() : _n(0), scc(0) {}
    two_sat(int n) : _n(n), _res(n), scc(2 * n) {}
    void imply(int i, bool f, int j, bool g) {
        scc.add_edge(2 * i + f, 2 * j + g);
    }
    void OR(int i, bool f, int j, bool g) {
        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
    }
    bool satisfiable() {
        auto id = scc.scc_ids().ss;
        for (int i = 0; i < _n; i++) {
            if (id[2 * i] == id[2 * i + 1]) return 0;
            _res[i] = id[2 * i] < id[2 * i + 1];
        }
        return 1;
    }
    vector<bool> res() { return _res; }
};

int yy, nn;
  
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    freopen("test.txt", "r", stdin);

    quickio
    int _;
    cin >> _;
    int s = 0;

    while(_--){
        int n, d, k;
        cin >> n >> d >> k;
        s += k;
 
        int x[k], y[k];
        rep(i, 0, k) cin >> x[i] >> y[i];
 
        two_sat sat(k);
        rep(i, 0, k){
            rep(j, i + 1, k){
                // if(i == j) continue;
                if(abs(x[i] - x[j]) <= 2*d && y[i] == y[j]){
                    sat.OR(i, 0, j, 0);
                }
                else if(abs(y[i] - y[j]) <= 2*d && x[i] == x[j]){
                    sat.OR(i, 1, j, 1);
                }
                if(abs(x[i] - x[j]) <= d && abs(y[i] - y[j]) <= d){
                    sat.imply(i, 0, j, 0);
                    sat.imply(j, 0, i, 0);
                    sat.imply(i, 1, j, 1);
                    sat.imply(j, 1, i, 1);
                }
            }
        }
 
        if(sat.satisfiable()){
            yy++;
            // cout << "Yes\n";
            // for(auto i : sat.res()) cout << i <<" ";
        }else{
            nn++;
            // cout << "No";
        }
        // cout << endl;
    }
    cout << yy << " " << nn << endl;
    cout << s << endl;
}

// if(abs(x[i] - x[j]) <= 2*d && y[i] == y[j]){
//     either i or j has to be vetical
// }
// else if(abs(y[i] - y[j]) <= 2*d && x[i] == x[j]){
//     either i or j has to be horizontal
// }
// if(abs(x[i] - x[j]) <= d && abs(y[i] - y[j]) <= d){
//     both i and j must face same direction
// }