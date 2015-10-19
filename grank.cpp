//https://code.google.com/codejam/contest/4284487/dashboard
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, p, n, w, m;
   	int sco;
	string s;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> p;
		vector<int> points(p, 0);
		for(int j = 0; j < p; j++) {
			cin >> points[j];
		}
		cin >> n;
		map<string, priority_queue<int, vector<int>, less<int> > > mp;
		for(int j = 0; j < n; j++) {
			cin >> w;
			for(int k = 0; k < p; k++) {
				cin >> s;
				mp[s].push((int)points[k] * w);
			}
		}
		cin >> m;
		vector<pair<string, int> > scores;

		for(auto a : mp) {
			s = a.first;
			sco = 0L;
			for(int j = 0; j < m && !a.second.empty(); j++) {
				sco += a.second.top();
				a.second.pop();
			}
			scores.emplace_back(make_pair(s, sco));
		}
		sort(scores.begin(), scores.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
				if(a.second != b.second) return a.second > b.second;
				else return a.first < b.first;
				});
		cout << "Case #" << i << ":" << endl;
		for(int j = 0, idx = 1; j < scores.size(); j++) {
			if(j && scores[j].second < scores[j - 1].second) idx = j + 1;
			cout << idx << ": " << scores[j].first << endl;
		}
	}
}
