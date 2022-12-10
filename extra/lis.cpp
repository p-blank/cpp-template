ll lis(vector<ll> v) 
{ 
    if(v.size() == 0) return 0; 
    vector<ll> tail(v.size(), 0); 
    ll length = 1; 
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++)
        if(v[i] > tail[length - 1]) tail[length++] = v[i]; 
        else{ 
            auto it = find(tail.begin(), tail.begin() + length, v[i]); 
            if (it != tail.begin() + length) continue; 
            it = upper_bound(tail.begin(), tail.begin() + length, v[i]); 
            *it = v[i]; 
    }
    return length; 
} 

ll lcis(ll a[], ll n) 
{ 
    unordered_map<ll, ll> mp; 
    ll dp[n]; 
    mem0(dp);
    ll mx = INT_MIN; 
    rep(i, 0, n){
        if(mp.find(a[i] - 1) != mp.end())
            ll lastIndex = mp[a[i] - 1] - 1, dp[i] = 1 + dp[lastIndex]; 
        else dp[i] = 1; 
        mp[a[i]] = i + 1; 
        mx = max(mx, dp[i]); 
    } 
    return mx; 
} 
