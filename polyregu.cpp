#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

int main() {
	int n;
	int x, y;
	vector<pair<int, int> > pts;
	map<pair<int, int>, int> mp;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x >> y;
		pair<int, int> p = make_pair(x, y);	
		pts.push_back(p);
		mp[p] = i;
	}
	vector<int> res;
	for(int i = 1; i < n; i++) {
		for(int j = i + 1; j <= n; j++) {
			pair<int, int> p1 = pts[i - 1], p2 = pts[j - 1];
			int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second;
			//已知正方形的两个非相邻顶点坐标，求另两点坐标：
			//以已知两点为直径画圆，则两点连线的中垂线与圆的交点即为所求
			int x3 = (x1 + x2 - y2 + y1) >> 1, y3 = (y1 + y2 + x2 - x1) >> 1;
			int x4 = (x1 + x2 + y2 - y1) >> 1, y4 = (y1 + y2 - x2 + x1) >> 1;
			pair<int, int> p3 = make_pair(x3, y3), p4 = make_pair(x4, y4);
			if(mp.count(p3) && mp.count(p4)) {
				res.push_back(i);
				res.push_back(j);
				res.push_back(mp[p3]);
				res.push_back(mp[p4]);
				cout << "4" << endl;
				sort(res.begin(), res.end());
				for(int k = 0; k < 4; k++) {
					cout << res[k] << endl;
				}
				return 0;
			}
		}
	}
	cout << "0" << endl;
	return 0;
}
