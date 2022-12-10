
//              ,-...  ..";";; / / ;  ;  \"'`.
//               .``"";;; ; ;;/ ; :;"';;/    `
//            ..::.  ;;;;;/   ;  :  .;""'"b;;,`.
//             .     . ; ; ,,;  : ."        \;; '
//          ..     . ;,:/  ; : , .           \;;`
//   .  .. .. . .. . : : ,, ; : , ,'""-.  .-'| ;'
//      .     . ..  .::/,,/  ;: ,   .o".   o"/ ' ; '
//    . ..      .. /, ,  ;  : ,          \  |'`` '  '
//      . /,, ;  : , ,                  ,.p / '' \' '
//        ./ ` , ;; ; ;:  ,"||               '\   \   ''
//       / . ,, , ,_, , , ";"| \      -==- / ' ' '     ''
//   / ;,;';           ;;;; |.  ,       - / "'; ; '    /
// = ...                ,,,/;;;:.=-  "'-./|\ '';':;    '
//                     ;;''.              `"|/   /
//                  ;; ;/"   .'           . | | '/
//                   ;'."                   ;\   '
//                   ; '  . .    ,         . |  '
//                 ;.'     . .             .|/\/
//                 ;.     .    /           .|/
//                ;.      .   /          .   \.
//                . \     .  '           .     `\                          
//                    .     .'           .'      "\
//              /      .    .|           '         '=
//             /        .   .|          '           "
//            /        / .   |          '           /
//           /        '     '           \.         /
//          /        /    . "            .        |
//          /       /      . '            .       \
//         /       |        . '             .      ;
//         O        \          `.            .     |
//          \        \       .   `.           ..   |
//           \\       \       .    `.          ..  |
//             \       \\       .     `.         ../
//               \      \\     .        `.        ..
//                 \      \\ .            ` .       ..
//                  \      \\                `        .
//                    \    /                   `.      .
//                     =\ /                      ` .    .
//                    // "                         /    .
//                   //"                         /      .
//                   u"    "                  //"\      .
//                   "    "                       \  |  .
//                  "     "                        \ |  .
//                  "     "                         \/  .
//                         "                        / /.
//                  "       "                      /// /
//                  \        "                    /// //
//                  "         "                   u"| /u
//                   "         "                    u |

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define repp(i, a, b) for(int i = a; i <= b; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b; i >= a; i--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a));
#define mem0(a) memset(a, 0, sizeof(a));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(m) repp(i, 1, m){ll a, b; cin >> a >> b; v[a].pb(b), v[b].pb(a);}
#define endl "\n"
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitsf(n) __builtin_popcount(n)
ll power(ll x, ll y); 

const ll MOD = 1000000007;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    
}
 
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}