/*...........tank.jpg............*/

#include <bits/stdc++.h>
using namespace std;
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

int mat[999][999];

int main() //PointBlank's code (⌐■_■)
{
    quickio 
    freopen("chk.txt", "r", stdin);

    int t;
    cin >> t;
    int n, d, k;
    cin >> n >> d >> k;
    int x[k], y[k];
    rep(i, 0, k) cin >> x[i] >> y[i];

    int c[k];
    rep(i, 0, k) cin >> c[i];

    rep(i, 0, k){
        if(c[i]){
            repp(j, max(0, x[i] - d), x[i] + d) mat[j][y[i]]++;
        }else{
            repp(j, max(0, y[i] - d), y[i] + d) mat[x[i]][j]++;
        }
    }

    int mx = 0;
    rep(i, 0, 999) rep(j, 0, 999) mx = max(mx, mat[i][j]);
    cout << mx << endl;
    rep(i, 0, 999) rep(j, 0, 999) if(mat[i][j] > 1) cout << i << " " << j << endl;
}