#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int main() {
	int n, i, j;
	int64 s, c;
	cin >> n;
	vector<pair<int64, int64> > segs;
	for(int i = 0; i < n; i++) {
		cin >> s >> c;
		if(segs.empty()) {
			segs.emplace_back(make_pair(s, s + c - 1));
			cout << s + c - 1 << endl;
		}
		else {
			auto lb = lower_bound(segs.begin(), segs.end(), make_pair(INT_MIN, s), 
					[](const pair<int64, int64>& a, const pair<int64, int64>& b) {
					return a.second < b.second;
					});
			if(lb == segs.end()) {
				segs.emplace_back(make_pair(s, s + c - 1));
				cout << s + c - 1 << endl;
			}
			else {
				auto ub = lb;
				if(lb->first <= s) {
					s = lb->second + 1;
					ub++;
				}
				int64 ns = min(s, lb->first), ne = s + c - 1;
				for(; ub != segs.end() && ne >= ub->first; ub++) {
					ne += ub->second - ub->first + 1;
					cout << ub->first << ", " << ub->second << ", " << ne << endl;
				}
				cout << ne << endl;
				segs.erase(lb, ub);
				segs.insert(lb, make_pair(ns, ne));
			}
		}
	}
}
