#include <bits/stdc++.h>
using namespace std;

/* DSU start */
int par[100005];
int rnk[100005];

void make_set(int i)
{
    par[i] = i;
    rnk[i] = 0;
}

int find_root(int i)
{
    if(i == par[i]) return i;
    return par[i] = find_root(par[i]);
}

void set_union(int x, int y)
{
    int a = find_root(x);
    int b = find_root(y);
    if(a != b)
    {
        if(rnk[a] < rnk[b]) swap(a,b);
        par[b] = a;
        if(rnk[b] == rnk[a]) rnk[a]++;
    }
}
/* DSU end */

/* 2-SAT stuff start */

set<int> adj[200005];
set<int> tadj[200005];
bool vis[200005];
int comp[200005];
int ans[200005];
vector<int> order;

void dfs1(int v)
{
    vis[v] = true;
    for(auto x : adj[v])
    {
        if(!vis[x]) dfs1(x);
    }
    order.push_back(v);
}

void dfs2(int v, int num)
{
    comp[v] = num;
    for(auto x : tadj[v])
    {
        if(comp[x] == -1) dfs2(x,num);
    }
}
/* 2-SAT stuff end */

void resetStuff(int k)
{
    for(int i = 0; i < k; i++)
    {
        adj[2*i].clear();
        adj[2*i+1].clear();
        tadj[2*i].clear();
        tadj[2*i+1].clear();
        vis[2*i] = false;
        vis[2*i+1] = false;
        comp[2*i] = -1;
        comp[2*i+1] = -1;
    }
    order.clear();
}

void solve()
{
    int n,d,k;
    cin>>n>>d>>k;

    resetStuff(k);

    map<int,vector<pair<int,int>>> forRow, forCol;
    int x,y;

    for(int i = 0; i < k; i++)
    {
        make_set(i);
        cin>>x>>y;
        forCol[x].push_back({y,i});
        forRow[y].push_back({x,i});
    }

    for(auto& xx : forRow)
    {
        sort(xx.second.begin(), xx.second.end());
    }

    for(auto& xx : forCol)
    {
        sort(xx.second.begin(), xx.second.end());
    }

    // for implementing sliding window

    queue<pair<int,int>> q; // x and y coordinates
    multiset<pair<pair<int,int>,int>> ms; // {y, x} and index

    // DSU step for combining non collinear ones that can overlap

    for(auto xx : forCol)
    {
        while(q.size() && q.front().first < xx.first-d)
        {
            ms.erase(ms.upper_bound({{q.front().second,q.front().first}, -1}));
            q.pop();
        }
        for(auto yi : xx.second)
        {
            auto itLower = ms.lower_bound({{yi.first-d, INT_MIN}, -1});
            auto itUpper = ms.lower_bound({{yi.first+1, INT_MIN}, -1});

            if(itLower != ms.end() && itLower->first.first <= yi.first-1)
            {
                set_union(yi.second, itLower->second);
            }
            if(itUpper != ms.end() && itUpper->first.first <= yi.first+d)
            {
                set_union(yi.second, itUpper->second);
            }
        }
        for(auto yi : xx.second)
        {
            q.push({xx.first,yi.first});
            ms.insert({{yi.first,xx.first},yi.second});
        }
    }

    // applying conditions for those that are in the same row
    for(auto xx : forRow)
    {
        for(int i = 1; i < xx.second.size(); i++)
        {
            int dist = xx.second[i].first - xx.second[i-1].first - 1;
            if(dist >= 2*d) continue;

            int a = find_root(xx.second[i-1].second);
            int b = find_root(xx.second[i].second);
            if(dist >= d)
            {
                adj[2*a].insert(2*b+1);
                adj[2*b].insert(2*a+1);

                tadj[2*b+1].insert(2*a);
                tadj[2*a+1].insert(2*b);
            }
            else
            {
                adj[2*a].insert(2*a+1);
                adj[2*b].insert(2*b+1);

                tadj[2*a+1].insert(2*a);
                tadj[2*b+1].insert(2*b);
            }
        }
    }

    // applying conditions for those that are in the same column
    for(auto xx : forCol)
    {
        for(int i = 1; i < xx.second.size(); i++)
        {
            int dist = xx.second[i].first - xx.second[i-1].first - 1;
            if(dist >= 2*d) continue;

            int a = find_root(xx.second[i-1].second);
            int b = find_root(xx.second[i].second);
            if(dist >= d)
            {
                adj[2*a+1].insert(2*b);
                adj[2*b+1].insert(2*a);

                tadj[2*b].insert(2*a+1);
                tadj[2*a].insert(2*b+1);
            }
            else
            {
                adj[2*a+1].insert(2*a);
                adj[2*b+1].insert(2*b);

                tadj[2*a].insert(2*a+1);
                tadj[2*b].insert(2*b+1);
            }
        }
    }

    // 2-SAT starts from here
    for(int i = 0; i < k; i++)
    {
        // proceed with only those ones that stay as roots after the DSU step
        if(find_root(i) == i)
        {
            if(!vis[2*i])
                dfs1(2*i);
            if(!vis[2*i+1])
                dfs1(2*i+1);
        }
    }
    
    int sz = order.size();
    int num = 0;
    for(int i = sz-1; i >= 0; i--)
    {
        if(comp[order[i]] == -1)
            dfs2(order[i],num++);
    }

    for(int i = 0; i < k; i++)
    {
        int rt = find_root(i);
        if(comp[2*rt] == comp[2*rt+1])
        {
            cout<<"No\n";
            return;
        }
        ans[i] = comp[2*rt] > comp[2*rt+1];
    }

    cout<<"Yes\n";
    for(int i = 0; i < k; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

int main()
{
    clock_t start,end;
    double time_taken;
    start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("2.in","r",stdin);
        freopen("2.out","w",stdout);
    #endif

    int tc;
    cin>>tc;

    while(tc--)
        solve();

    end = clock();
    time_taken = double(end-start)/CLOCKS_PER_SEC;
    // cout<<time_taken<<" sec";
}	