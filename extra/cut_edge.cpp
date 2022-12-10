vector<ll> v[100005], ap;
ll in[100005], low[100005], vis[100005], par[100005];
vector<pair<ll, ll> > bridge;
ll n, m, t;
 
void dfs(ll s)
{
    vis[s] = 1;
    in[s] = low[s] = t++;
    ll child = 0;
    for(auto &i : v[s]){
        if(!vis[i]){
            child++;
            par[i] = s;
            dfs(i);
            low[s] = min(low[s], low[i]);
            if(par[s] == 0 && child > 1) ap.pb(s);
            if(low[i] > in[s]) bridge.pb(s, i);
            if(par[s] != 0 && low[i] >= in[s]) ap.pb(s);
        }else if(par[s] != i) low[s] = min(low[s], in[i]);
    }
}
        