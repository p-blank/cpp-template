class Bip{ 
    public: 
    int m, n; 
    vector<int> *v; 
    int *pa, *pb, *dis; 
    Bip(int m, int n){ 
        this->m = m, this->n = n; 
        v = new vector<int>[m+1]; 
    } 
    void edg(int a, int b){ 
        v[a].push_back(b);  
    } 

    bool bfs() { 
        queue<int> q;
        repp(a, 1, m){
            if(pa[a] == 0) dis[a] = 0, q.push(a);
            else dis[a] = inf;
        }
        dis[0] = inf; 
        while(q.size()){
            auto a = q.front(); q.pop(); 
            if(dis[a] < dis[0]) { 
                vector<int>::iterator i; 
                for (i=v[a].begin(); i != v[a].end(); ++i){ 
                    auto b = *i; 
                    if (dis[pb[b]] == inf) dis[pb[b]] = dis[a] + 1, q.push(pb[b]); 
                } 
            } 
        } 
        return (dis[0] != inf); 
    }

    bool dfs(int a) { 
        if(a == 0) return 1; 
        vector<int>::iterator i; 
        for (i = v[a].begin(); i != v[a].end(); ++i) { 
            int b = *i; 
            if (dis[pb[b]] == dis[a] + 1 && dfs(pb[b]) == 1){
                pb[b] = a, pa[a] = b;
                return 1;
            } 
        } 
        dis[a] = inf; 
        return 0; 
    }  

    int max_match(){ 
        pa = new int[m+1]; 
        pb = new int[n+1]; 
        dis = new int[m+1]; 
        repp(a, 0, m) pa[a] = 0; 
        repp(b, 0, n) pb[b] = 0; 
      
        int res = 0; 
        while(bfs()) repp(a, 1, m)if (pa[a]==0 && dfs(a)) res++; 
        return res; 
    }  
}; 