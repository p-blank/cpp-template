ll n;
vector<ll> T(4*N, 0);

void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        T[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        T[v] = 0;
    }
}

ll get(ll v, ll tl, ll tr, ll idx) {
    if(tl == tr) return T[v];
    ll tm = (tl + tr)/2;
    if(idx <= tm) return T[v] + get(v*2, tl, tm, idx);
    else return T[v] + get(v*2 + 1, tm + 1, tr, idx);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if(l > r) return;
    if (l == tl && r == tr) {
        T[v] += val;
    } else {
        ll tm = (tl + tr) / 2;
        update(v*2    , tl    , tm, l, min(r, tm), val);
        update(v*2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}