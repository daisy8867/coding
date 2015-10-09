#include <bits/stdc++.h>
using namespace std;
struct pairhash {
	public:
		template <typename T, typename U> 
			std::size_t operator()(const std::pair<T, U> &x) const
			{
				return std::hash<T>()(x.first)^std::hash<T>()(x.second);
			}
};

void dfs(vector<bool>& vis, vector<int>& size, vector<unordered_set<int> >& graph, vector<vector<long long int> >& edges, map<pair<int, int>, int>& mp, int n, int u) {
	vis[u] = true;
	for(int v : graph[u]) {
		if(!vis[v]) {
			dfs(vis, size, graph, edges, mp, n, v);
			size[u] += size[v];
		}
	}
}
int main() {
	int n, m, u, v, k;
	while(cin >> n >> m) {
		vector<vector<long long int> > edges(n - 1, vector<long long int>(4, 0));
		vector<unordered_set<int> > graph(n + 1);
		map<pair<int, int>, int> mp; 
//		unordered_map<pair<int, int>, int, pairhash> mp; 
		for(int i = 1; i < n; i++) {
			cin >> u >> v >> k;
			edges[i - 1][0] = u;
			edges[i - 1][1] = v;
			edges[i - 1][2] = k;
			mp[make_pair(u, v)] = i - 1;
			graph[u].insert(v);
			graph[v].insert(u);
		}
		vector<bool> vis(n + 1, false);
		vector<int> size(n + 1, 1);
		long long int thd = 0L;
		dfs(vis, size, graph, edges, mp, n, 1);
		for(int i = 0; i < n - 1; i++) {
			if(size[edges[i][0]] > size[edges[i][1]]) {
				edges[i][3] = 1L * size[edges[i][1]] * (n - size[edges[i][1]]);
			}
			else {
				edges[i][3] = 1L * size[edges[i][0]] * (n - size[edges[i][0]]);
			}
			thd += 1L * edges[i][2] * edges[i][3];
		}
		for(int i = 0; i < m; i++) {
			string q;
			cin >> q;
			if(q[0] == 'Q') {
				cout << thd << endl;
			}
			else {
				cin >> u >> v >> k;
				int id = mp[make_pair(u, v)];
//				cout << "edge " << id << " used " << edges[id][3] << " times " << edges[id][2] << "->" << k << endl;
				thd += (k - edges[id][2]) * edges[id][3];
				edges[id][2] = k;
			}
		}
	}
}
