ll power(ll x, ll y){ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}

vector<ll> fact, ifact;
void gen_fact(int _lim_){
    fact.resize(_lim_ + 5, 1); ifact.resize(_lim_ + 5, 1);
    rep(i, 1, fact.size()) (fact[i] = fact[i - 1] * i) %= MOD;
    rep(i, 1, fact.size()) ifact[i] = power(fact[i], MOD - 2);
}

ll ncr(ll n, ll r){
    if(n < r) return 0;
    return (((fact[n] * ifact[n - r]) % MOD) * ifact[r]) % MOD;
}