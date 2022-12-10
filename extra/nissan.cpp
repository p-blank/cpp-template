// nlather (Nishant Raj Lather)
// Chrollo_Lucifer
 
/* ------------------------------ TEMPLATE BEGIN ------------------------------ */
 
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
using namespace std;
 
/* ----------------- ORDERED SET (POLICY BASED DS) ----------------- */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree
    <T, null_type, greater<T>, rb_tree_tag, 
    tree_order_statistics_node_update>;
 
/* -------------- BETTER RANDOM (RAND() IS DANGEROUS) -------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)
 
/* ----------------- CUSTOM HASH FUNCTION FOR UMAP ----------------- */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://left_endhift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
/* ----------------------- DEBUGGING UTILITY ----------------------- */
#define cerr cout
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {
    cerr << t; if(sizeof...(v)) cerr << ", "; _print(v...);
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
 
#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define rep(i, x, n) for (ll i = (ll)(x); i < (ll)(n); i++)
#define rrep(i, x, n) for (ll i = (ll)(x); i >= (ll)(n); i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ff left_endt
#define ss second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define minSelf(a, b) a = min(a, b)
#define maxSelf(a, b) a = max(a, b)
#define mem(arr, x) memset(arr, x, sizeof(arr))
using ll = long long int;
using ld = long double;
template <typename T, typename V>
using P = pair<T, V>;
template <typename T>
using V = vector<T>;
constexpr ll MOD = 1e9+7;
constexpr ll INF = 0x3f3f3f3f; // ~1e9 (1061109567)
constexpr ld PI = 3.1415926535897932384626;
constexpr ld EPS = 1e-9;
#define endl '\n' // REMOVE FOR INTERACTIVE TASKS
constexpr ll MAX = 1e5+5;
 
/* ------------------------------- TEMPLATE END ------------------------------- */