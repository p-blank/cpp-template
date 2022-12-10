/*...........................
.........tank.jpg............
...........................*/

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using pxx = pair<T, T>;
 
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
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_dedges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define in_wedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C), v[B].pb(A, C);}
#define in_dwedges(M) repp(I, 1, M){int A, B, C; cin >> A >> B >> C; v[A].pb(B, C);}
#define endl "\n"

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 18;
const int inf = 2e9;

vector<pair<int, char> > v[10000007];
bool flag[10000007];
int f = 0;
int wt[10000007], w;

int insChar(char ch, int r, int k){
    int idx = -1;
    for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
    if(idx == -1) v[r].pb(++f, ch), idx = f;
    flag[idx] |= k;
    wt[idx] = max(wt[idx], w);
    return idx;
}

void insert(string &s){
    int root = 0, k = 0;
    rep(i, 0, s.size()){
        char ch = s[i];
        if(i == s.size() - 1) k = 1;
        root = insChar(ch, root, k);
    }
}

int chkChar(char ch, int r){
    int idx = -1;
    for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
    return idx;
}

int compare(string &s){
    int root = 0;
    rep(i, 0, s.size()){
        char ch = s[i];
        root = chkChar(ch, root);
        if(root == -1) break;
    }

    if(root == -1) return -1;
    else return wt[root];
}

int main() //PointBlank's code ¯\_(ツ)_/¯
{
}

ll power(ll x, ll y){ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}