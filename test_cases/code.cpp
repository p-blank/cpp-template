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

    freopen("test.txt", "r", stdin);
    int c = 0;
    
    int t, k, d, n;
    cin >> t;

    if(t > 1e2) c++;
    int s = 0, ss = 0;
    while(t--){
        set<pxx<int> > st;
        cin >> n >> d >> k;
        s += k;
        if(n > 1e5) c++;
        if(d > 1e5) c++;
        if(k > 1e5) c++;
        int x, y;
        rep(i, 0, k){
            cin >> x >> y;
            st.emplace(x, y);
            if(x > n || y > n) c++;
        }
        ss += st.size();
    }
    cout << c;
    cout << s << endl;
    if(s > 1e5) c++;
    cout << c << endl << ss;
    
}   