struct Dsu{
    vector<int> par;
    vector<int> _sz;
    int n;

    Dsu(int _n){
        n = _n;
        par.resize(n + 3, 0);
        _sz.resize(n + 3, 1);
        repp(i, 0, n) par[i] = i;
    }

    int root(int node) {
        if (node == par[node]) return node;
        return par[node] = root(par[node]);
    }

    int size(int node){ return _sz[root(node)]; }

    void merge(int a, int b) {
        a = root(a), b = root(b);
        if(a != b) {
            if(_sz[a] < _sz[b]) swap(a, b);
            par[b] = a;
            _sz[a] += _sz[b];
        }
    }
};