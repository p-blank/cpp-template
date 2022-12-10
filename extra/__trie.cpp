struct Trie{
    int MX, f, w;
    vector<int> wt;
    vector<vector<pair<int, char> > > v;
    vector<bool> leaf;

    Trie(){
        MX = 2e6 + 6, f = 0;
        wt.resize(MX, 0);
        leaf.resize(MX, 0);
        v.resize(MX);
    }

    int insChar(char ch, int r, bool k){
        int idx = -1;
        for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
        if(idx == -1) v[r].pb(++f, ch), idx = f;
        leaf[idx] = leaf[idx] || k;
        wt[idx] = max(wt[idx], w);
        return idx;
    }

    void insert(string &s){
        int root = 0; bool k = 0;
        rep(i, 0, s.size()){
            char ch = s[i];
            if(i == s.size() - 1) k = 1;
            root = insChar(ch, root, k);
        }
    }

    int chkChar(char ch, int r){
        int idx = -1;
        for(auto p : v[r]) if(p.ss == ch) idx = p.ff;
        return idx;
    }

    int compare(string &s){
        int root = 0;
        rep(i, 0, s.size()){
            char ch = s[i];
            root = chkChar(ch, root);
            if(root == -1) break;
        }
        if(root == -1) return -1;
        else return wt[root];
    }
};