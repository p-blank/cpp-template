struct BIT{
    ll N;
    vector<ll> T;
    BIT(){}
    BIT(ll n) {
        N = n;
        T.resize(n + 1, 0);
    }
    void resize(ll n){
        N = n;
        T.resize(n + 1, 0);
    }
    void add(ll idx, ll val) {
        for(; idx <= N; idx += idx &- idx) T[idx] += val;
    }
    ll sum(ll idx) {
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx) res += T[idx];
        return res;
    }
    ll get_sum(ll l, ll r) {
        return sum(r)-sum(l-1);
    }
};

// RANGE QUERY BIT

struct BIT
{
    ll N;
    vector<ll> T1, T2;
    BIT(){}
    BIT(ll n) {
        N = n;
        T1.resize(n + 1, 0);
        T2.resize(n + 1, 0);
    }
    void resize(ll n){
        N = n;
        T1.resize(n + 1, 0);
        T2.resize(n + 1, 0);
    }
    void add(vector<ll> &T, ll idx, ll val){
        for(; idx <= N; idx += idx & -idx) T[idx] += val;
    }

    void range_add(ll l, ll r, ll val){
        add(T1, l, val);
        add(T1, r + 1, -val);
        add(T2, l, val*(l - 1));
        add(T2, r + 1, -val*r);
    }

    ll sum(vector<ll> &T, ll idx){
        ll res = 0;
        for(; idx > 0; idx -= idx & -idx) res += T[idx];
        return res;
    }

    ll prefix_sum(ll idx){
        return sum(T1, idx)*idx - sum(T2, idx);
    }

    ll range_sum(ll l, ll r){
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};