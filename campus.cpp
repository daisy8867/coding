#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	const int M = 1000001;
	int t, n, m;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":" << endl;
		cin >> n >> m;
		vector<vector<int> > p(n, vector<int>(n, M));
		vector<pair<pair<int, int>, int> > e;
		vector<int> res;
		int a, b, c;
		for(int j = 0; j < n; j++) {
			p[j][j] = 0;
		}
		for(int j = 0; j < m; j++) {
			cin >> a >> b >> c;
			p[a][b] = min(p[a][b], c);
			p[b][a] = min(p[b][a], c);
			e.emplace_back(make_pair(make_pair(a, b), c));
		}
		for(int k = 0; k < n; k++) {
			for(int u = 0; u < n; u++) {
				for(int v = 0; v < n; v++) {
					p[u][v] = min(p[u][k] + p[k][v], p[u][v]);
				}
			}
		}
		for(int k = 0; k < e.size(); k++) {
			a = e[k].first.first;
			b = e[k].first.second;
			c = e[k].second;
			int flag = 0;
			for(int u = 0; u < n && !flag; u++) {
				for(int v = 0; v < n && !flag; v++) {
					if(p[u][a] + c + p[b][v] == p[u][v]) {
						flag = 1;
					}
				}
			}
			if(!flag){
				cout << k << endl;
			}

		}
	}
}
