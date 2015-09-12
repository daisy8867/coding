#include "header.h"
const int M = 100000001;
int dijkstra(int v, int start, int target, vector<vector<int> >& dis) {
	vector<bool> vis(v + 1, false);
	vector<int> dist(dis[start]);
	vis[start] = true;
	for(int i = 1; i <= v; i++) {
		int tmp = M;
	    int u = start;	
		for(int j = 1; j <= v; j++) {
			if(!vis[j] && dist[j] < tmp) {
				u = j;
				tmp = dist[j];
			}
		}
		vis[u] = true;
		for(int j = 1; j <= v; j++) {
			if(!vis[j] && dis[u][j] < M) {
				dist[j] = min(dist[u] + dis[u][j], dist[j]);
			}
		}
	}
	return dist[target];
}

int main() {
	int v, e, s, t, a, b, d;
	cin >> v >> e >> s >> t;
	vector<vector<int> > dis(v + 1, vector<int>(v + 1, M));
	for(int i = 1; i <= v; i++) {
		dis[i][i] = 0;
	}
	for(int i = 0; i < e; i++) {
		cin >> a >> b >> d;
		dis[a][b] = min(dis[a][b], d);
		dis[b][a] = min(dis[b][a], d);
	}
	cout << dijkstra(v, s, t, dis) << endl;
}
