#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b; i >= a; i--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define in_edges(M) repp(I, 1, M)\
{int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 3;
ll power(ll x,ll y){ll res = 1; x%=MOD;while(y>0) \
{if(y&1)res=(res*x)%MOD;y=y>>1,x=(x*x)%MOD;}return res;}
 
void pre();
void solve();
void post();
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    pre();
    repp(tst, 1, t){
        solve();
        post();
    }
}
 
/*------------------------------------------------------------*/
 
void pre(){}
 
void solve(){
}
 
void post(){}