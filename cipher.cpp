//poj 1026
#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

void findLoop(const vector<int>& seq, vector<int>& loop) {
	int sz = seq.size();
	for(int i = 0; i < sz; i++) {
		int tmp = seq[i] - 1;
		while(tmp != i) {
			tmp = seq[tmp] - 1;
			loop[i]++;
		}
	}
}

void trans(const int k, const vector<int>& loop, const vector<int>& seq, const string& s, string& res) {
	int len = s.length();
	int r = len;
	for(int i = 0; i < len; i++) {
		int kk = k % loop[i];
		int t = i;
		while(kk--) {
			t = seq[t] - 1;
		}
		res[t] = s[i];
		r = max(t, r);
	}
	res.resize(r + 1);
}
int main() {
	int n, k;
	char s[202], res[202];
	while(cin >> n) {
		vector<int> seq(n, 0);
		vector<int> loop(n, 1);
		for(int i = 0; i < n; i++) {
			cin >> seq[i];
		}
		findLoop(seq, loop);
		while(cin >> k, k) {
			getchar();
			cin.getline(s, n + 1);
//			string s(n, ' ');
//			getline(cin, s);
			int len = strlen(s);
			for(int i = len; i < n; i++) {
				s[i] = ' ';
			}
			s[n] = '\00';
			for(int i = 0; i < n; i++) {
				int kk = k % loop[i];
				int t = i;
				while(kk--) {
					t = seq[t] - 1;
				}
				res[t] = s[i];
			}
			res[n] = '\00';
//			string res(n, ' ');
//			trans(k, loop, seq, s, res);
			cout << res << endl;
		}
		cout << endl;
	}
}
