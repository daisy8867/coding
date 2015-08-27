#include <deque>
#include <iostream>
#include <unordered_set>
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

void printQ(deque<pair<int, int> > q) {
	for(int i = 0; i < q.size(); i++) {
		cout << q[i].first << ", " << q[i].second << endl;
	}
}
int main() {
	int t, n, r, c, x;
	char a;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	cin >> t;
	for(int i = 1; i <= t; i++) {
		deque<pair<int, int> > s;
		unordered_set<pair<int, int>, pairhash> ss;
		unordered_set<pair<int, int>, pairhash> vis;
		s.emplace_back(make_pair(1, 1));
		ss.insert(s[0]);
		int d = 0;
		cin >> n >> r >> c;
		int step = 0, flag = 1;
		for(int j = 0; j < n; j++) {
			cin >> x >> a;
			while(step < x && flag) {
				pair<int, int> nh = make_pair((s[0].first + dx[d] + r - 1) % r + 1, (s[0].second + dy[d] + c - 1) % c + 1);
//				cout << "new head: " << nh.first << ", " << nh.second << endl;
				s.push_front(nh);
//				cout << ((nh.first + nh.second) & 1) << endl;
				if(vis.find(nh) == vis.end() && ((nh.first + nh.second) & 1)) {
					vis.insert(nh);
				}
				else {
//					cout << "delete end " << s[s.size() - 1].first << ", " << s[s.size() - 1].second << endl;
					ss.erase(ss.find(s[s.size() - 1]));
					s.pop_back();
				}

				if(ss.find(nh) == ss.end()) {
					ss.insert(s[0]);
				}
				else {
					flag = 0;
				}
//				cout << "step: " << step << endl;
//				printQ(s);
				step++;
			}
			if(flag) {
				switch (a){
					case 'L': {
								  d = (d + 3) % 4;
								  break;						  
							  }
					case 'R': {
								  d = (d + 1) % 4;
								  break;
							  }
					default: break;
				}
			}
		}
//		while(step < 1000000000 && flag) {
		while(step < 2000000 && flag) { // after all turn action, it will not change direction, thus will not go more than 2R or 2C step for growing body, after that, it will go until timeout
			pair<int, int> nh = make_pair((s[0].first + dx[d] + r - 1) % r + 1, (s[0].second + dy[d] + c - 1) % c + 1);
//			cout << "new head: " << nh.first << ", " << nh.second << endl;
			s.push_front(nh);
//			cout << ((nh.first + nh.second) & 1) << endl;
			if(vis.find(nh) == vis.end() && ((nh.first + nh.second) & 1)) {
				vis.insert(nh);
			}
			else {
//				cout << "delete end " << s[s.size() - 1].first << ", " << s[s.size() - 1].second << endl;
				ss.erase(ss.find(s[s.size() - 1]));
				s.pop_back();
			}
			if(ss.find(nh) == ss.end()) {
				ss.insert(s[0]);
			}
			else {
				flag = 0;
			}
//			cout << "step: " << step << endl;
//			printQ(s);
			step++;
		}
		cout << "Case #" << i << ": " << s.size() << endl;
	}
}
