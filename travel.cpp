#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<vector<int> > >& mp, int n, int d, int s) {
    const int _max = 50 * 500;
    vector<int> dist(mp[1][s]);
    auto cmp = [] (const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> uq(cmp);
    vector<bool> vis(n + 1, false);
    for(int i = 1; i <= n; i++) {
	dist[i] += s;
    }

//    vis[1] = true;
//    for(int i = 1; i <= n; i++) {
//	int u = 1;
//	int tmp = _max;
//	for(int j = 1; j <= n; j++) {
//	    if(!vis[j] && dist[j] < tmp) {
//		u = j;
//		tmp = dist[j];
//	    }
//	}
//	vis[u] = true;
//	for(int j = 1; j <= n; j++) {
//	    if(!vis[j]) {
//		dist[j] = min(dist[u] + mp[u][dist[u] % 24][j], dist[j]);
//	    }
//	}
//    }
    uq.push(make_pair(1, dist[1]));
    while(!uq.empty()) {
	int u = uq.top().first;
	while(vis[u]) {
	    uq.pop();
	    u = uq.top().first;
	}
//	cout << endl << "u: " << u;
	vis[u] = true;
	uq.pop();
	if(u == d) break;
	for(int i = 2; i <= n; i++) {
	    if(!vis[i]) {
		dist[i] = min(dist[u] + mp[u][dist[u] % 24][i], dist[i]);
	    	uq.push(make_pair(i, dist[i]));
	    }
	}
    }
    return dist[d] - s;
}

int main() {
    int t, n, m, q, a, b, c, d, s;
    cin >> t;
    const int _max = 50 * 500;
    for(int i = 1; i <= t; i++) {
	cin >> n >> m >> q;
	vector<vector<vector<int> > > mp (n + 1, vector<vector<int> >(24, vector<int>(n + 1, _max)));
	for(int j = 1; j <= n; j++) {
	    for(int k = 0; k < 24; k++) {
		mp[j][k][j] = 0;
	    }
	}
	for(int j = 0; j < m; j++) {
	    scanf("%d %d", &a, &b);
//	    cin >> a >> b;
	    for(int k = 0; k < 24; k++) {
		scanf("%d", &c);
		mp[a][k][b] = c;
		mp[b][k][a] = c;
//		cin >> c;
//		mp[a][k][b] = min(c, mp[a][k][b]);
//		mp[b][k][a] = min(c, mp[b][k][a]);
	    }
	}
	cout << "Case #" << i << ":";
	for(int j = 0; j < q; j++) {
	    cin >> d >> s;
	    int ret = dijkstra(mp, n, d, s);
	    ret = (ret < _max) ? ret : -1;
	    cout << " " << ret;
	}
	cout << endl;
    }
}
