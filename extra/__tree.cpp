struct Tree{
    vector<vector<int> > v;
    vector<int> dis;
    int n;
 
    Tree(int _n){
        n = _n;
        v.resize(n + 2);
        dis.resize(n + 2);
 
        in_edges(n - 1);
    }
 
    int bfs(int s){
        dis.assign(n + 2, 0);
        queue<int> q;
        q.push(s);
        while(q.size()){
            auto p = q.front();
            q.pop();
            for(auto i : v[p]) if(i != s && !dis[i]){
                dis[i] = dis[p] + 1;
                q.push(i);
            }
        }
        int x = 0;
        repp(i, 1, n) if(dis[i] > dis[x]) x = i;
        return x;
    }
};