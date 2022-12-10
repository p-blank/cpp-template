bool color[100005];
vector<int> v[100005];
bool vis[100005];

bool bipartite(int s)
{
	vis[s] = 1;
	for(auto i : v[s]){
		if(vis[i])
			if(color[i] == color[s]) return 0;
			else continue;
		color[i] = !color[s];
		if(!bipartite(i)) return 0;
	}
	return 1;
}
