vector<ll> dis;
vector<bool> vis;
//declared vis, dis
void dijkstra(ll s){
    dis.resize(N, INF);
    vis.resize(N, 0);

    dis[s] = 0;
    priority_queue<pair<ll, ll> > pq;
    pq.push({0, s});

    while(pq.size()){
        auto p = pq.top().ss;
        pq.pop();
        if(vis[p]) continue;
        vis[p] = 1;
        for(auto i : v[p]) if(dis[i.ff] > dis[p] + i.ss){
            dis[i.ff] = dis[p] + i.ss;
            pq.push({-dis[i.ff], i.ff});
        }
    }
}