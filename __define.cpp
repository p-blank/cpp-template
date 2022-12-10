/*...........................
.........tank.jpg............
...........................*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template<typename T> using pxx = pair<T,T>;
 
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

const ll sp1 = 1e12 + 39; 
const ll sp2 = 1e15 + 1e5 + 11;
const ll INF = 1e18 + 18;
const ll MOD = 1e9 + 7;
const int inf = 2e9 + 9;
const size_t N = 1e6 + 6;
 
int main() //PointBlank's code (⌐■_■)
{
}

ll power(ll x, ll y){ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}