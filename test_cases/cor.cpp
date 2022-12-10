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
 
struct Dsu{
    vector<int> par;
    vector<int> _sz;
    int n;
 
    Dsu(int _n){
        n = _n;
        par.resize(n + 3, 0);
        _sz.resize(n + 3, 1);
        repp(i, 0, n) par[i] = i;
    }
 
    int root(int node) {
        if (node == par[node]) return node;
        return par[node] = root(par[node]);
    }
 
    int size(int node){ return _sz[root(node)]; }
 
    void merge(int a, int b) {
        a = root(a), b = root(b);
        if(a != b) {
            if(_sz[a] < _sz[b]) swap(a, b);
            par[b] = a;
            _sz[a] += _sz[b];
        }
    }
};
 
vector<pxx<int> > XY[N];
vector<pxx<int> > YX[N];
int yy, nn;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    freopen("test.txt", "r", stdin);

    quickio
    int _;
    cin >> _;
    while(_--){
        int n, d, k;
        cin >> n >> d >> k;
 
        set<int> xs, ys;
        rep(i, 0, k){
            int x, y;
            cin >> x >> y;
            xs.emplace(x);
            ys.emplace(y);
            XY[x].pb(y, i);
            YX[y].pb(x, i);
        }
        for(auto x : xs) sort(all(XY[x]));
        for(auto y : ys) sort(all(YX[y]));
 
        Dsu dsu(k);
        multiset<pair<pxx<int>, int> > yxi;
        multiset<pxx<int> > xys;
        for(auto x : xs){
            while(xys.size() && x-d > (*xys.begin()).ff){
                auto [xx, yy] = *xys.begin();
                xys.erase(xys.begin());
                auto ub = yxi.UB(MP( MP(yy, xx), -1 ));
                yxi.erase(ub);
            }
 
            for(auto [y, idx] : XY[x]){
                auto it = yxi.UB(MP( MP(y + 1, -1), -1 ));
                if(it != yxi.end() && (*it).ff.ff <= y + d) dsu.merge(idx, (*it).ss);
                it = yxi.UB(MP( MP(y - d, -1), -1 ));
                if(it != yxi.end() && (*it).ff.ff <= y - 1) dsu.merge(idx, (*it).ss);
 
            }
 
            for(auto [y, idx] : XY[x]){
                xys.insert(MP(x, y));
                yxi.insert(MP( MP(y, x), idx ));
            }
        }
 
        two_sat sat(k);
        for(auto x : xs){
            rep(it, 1, XY[x].size()){
                if(XY[x][it].ff - XY[x][it-1].ff > 2*d) continue;
                auto i = dsu.root(XY[x][it].ss);
                auto j = dsu.root(XY[x][it-1].ss);
                if(XY[x][it].ff - XY[x][it-1].ff <= d){
                    sat.imply(i, 0, i, 1);
                    sat.imply(j, 0, j, 1);
                }else{
                    sat.OR(i, 1, j, 1);
                }
            }
        }
 
        for(auto y : ys){
            rep(it, 1, YX[y].size()){
                if(YX[y][it].ff - YX[y][it-1].ff > 2*d) continue;
                auto i = dsu.root(YX[y][it].ss);
                auto j = dsu.root(YX[y][it-1].ss);
                if(YX[y][it].ff - YX[y][it-1].ff <= d){
                    sat.imply(i, 1, i, 0);
                    sat.imply(j, 1, j, 0);
                }else{
                    sat.OR(i, 0, j, 0);
                }
            }
        }
 
        if(sat.satisfiable()){
            yy++;
        }else{
            nn++;
        }
 
        for(auto x : xs) XY[x].clear();
        for(auto y : ys) YX[y].clear();
    }
    cout << yy << " " << nn << endl;
}