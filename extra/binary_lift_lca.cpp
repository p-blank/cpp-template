// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░
 
//PointBlank's code (⌐■_■)
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define in_edges3(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C), v[B].pb(A, C);}
#define endl "\n"
 
const ll MOD = 1000000007;
const int INF = 2e9;
 
const int N = 3e5 + 5;
const int LOG = 20;
 
vector<pair<int, int> > v[N];
int up[N][LOG];
int mne[N][LOG];
int in[N], out[N], lvl[N];
int clk;
 
void dfs(int s, int par, int w){
    in[s] = ++clk;
 
    lvl[s] = lvl[par] + 1;
    up[s][0] = par;
    rep(i, 1, LOG) up[s][i] = up[up[s][i-1]][i-1];
    mne[s][0] = w;
    rep(i, 1, LOG) mne[s][i] = min(mne[up[s][i - 1]][i - 1], mne[s][i - 1]);
 
    for(auto i : v[s]) if(i.ff != par) dfs(i.ff, s, i.ss);
    out[s] = ++clk;
}
 
bool is_ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}
 
int lca(int u, int v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    rrep(i, LOG - 1, 0) if(!is_ancestor(up[u][i], v)) u = up[u][i];
    return up[u][0];
}
 
int lift(int s, int x){
    if(x == 0) return INF;
    rep(i, 0, LOG){
        int jump = 1 << i;
        if(jump == x) return mne[s][i];
        if(jump > x) return min(mne[s][i - 1], 
                     lift(up[s][i - 1], x - jump/2));
    }
}
 
int dis(int par, int x){
    return lvl[x] - lvl[par];
}
 
int qry(int a, int b){
    int par = lca(a, b);
    int d1 = dis(par, a);
    int d2 = dis(par, b);
 
    return min(lift(a, d1), lift(b, d2));   
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    rep(i, 0, N) rep(j, 0, LOG) mne[i][j] = INF;
    int n, m;
    cin >> n >> m;
    in_edges3(m);
 
    dfs(1, 1, INF);
    out[0] = clk;
    
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << qry(a, b) << endl;
    }
}
 
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}