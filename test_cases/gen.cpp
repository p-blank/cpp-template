/*...........tank.jpg............*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

using ll = long long;
using ld = long double;
template<typename T> using pxx = pair<T, T>;
 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define _(container) (int)(container.size())
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(M) repp(lup_, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define endl "\n"

const size_t N = 1e6 + 6;

int main() //PointBlank's code (⌐■_■)
{
    // quickio 

    freopen("test.txt", "w", stdout);
    int t = 100;
    cout << t << endl;
    
    int n = 1e5;
    while(t--){
        int d = rnd(10, 1e4);
        int k = 1e3;
        cout << n << " " << d << " " << k << endl;

        set<pxx<int> > st;
        rep(i, 0, k){
            int x = rnd(1e3, 1e5);
            int y = rnd(1e3, 1e5);
            while(st.count({x, y})) x = rnd(1e3, 1e5), y = rnd(4e3, 1e5);
            st.emplace(x, y);
            cout << x << " " << y << endl;
        }
    }
}   