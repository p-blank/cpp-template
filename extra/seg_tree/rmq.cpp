ll n;
vector<ll> T(4*N, 0);

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        T[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        T[v] = T[v*2] ^ T[v*2+1];
    }
}

ll get_xor(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return T[v];
    ll tm = (tl + tr) / 2;
    return get_xor(v*2  , tl  , tm, l, min(r, tm)) ^ 
           get_xor(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(ll v, ll tl, ll tr, ll idx, ll val) {
    if (tl == tr) {
        T[v] = val;
    } else {
        ll tm = (tl + tr) / 2;
        if (idx <= tm) update(v*2, tl, tm, idx, val);
        else update(v*2+1, tm+1, tr, idx, val);
        T[v] = T[v*2] ^ T[v*2+1];
    }
}