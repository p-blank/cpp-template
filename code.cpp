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
const ll INF = 1e18;
 
const int N = 5e5 + 5;
 
vector<int> v[N];
int arr[N];
int m[N];
int n, k;
 
bool chk(int sz){
    rep(i, 0, N) m[i] = 0;
    int c = 0;
    repp(i, 1, sz) for(auto j : v[arr[i]]){
        m[j]++;
        if(m[j] == 1) c++;
    }
    repp(i, 1, n - sz + 1){
        for(auto j : v[arr[i - 1]]){
            m[j]--;
            if(m[j] == 0) c--;
        }
        if(c >= k) return 1;
        for(auto j : v[arr[i + sz]]){
            m[j]++;
            if(m[j] == 1) c++;
        }
    }
    return 0;
}
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    rep(i, 2, N) if(v[i].size() == 0){
        v[i].pb(i);
        for(auto j = 2*i; j < N; j += i) v[j].pb(i);
    }
 
    quickio
    cin >> n >> k;
    repp(i, 1, n) cin >> arr[i];
 
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r)/2;
        if(chk(mid)) r = mid - 1;
        else l = mid + 1;
    }
 
    if(l > n) cout << -1;
    else cout << l;
}
 
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}