#include <bits/stdc++.h>
using namespace std;

void dfs(string& s, vector<int>& count, int len, int left) {
	if(s.length() == len) return;
	for(int i : count) {
		if(i > left) return;
	}
	for(int i = 0; i < 26; i++) {
		if(count[i] && s.back() != ('a' + i)) {
			s.push_back('a' + i);
			count[i]--;
			dfs(s, count, len, (len - s.length() + 1) >> 1);
			if(s.length() == len) return;
			else {
				s.pop_back();
				count[i]++;
			}
		}
	}
}
int main() {
	string s;
	vector<int> count(26, 0);
	cin >> s;
	int len = s.length();
	int _m = (len + 1) >> 1;
	for(char &c : s) {
		count[c - 'a']++;
		if(count[c - 'a'] > _m) {
			cout << "-1" << endl;
			return 0;
		}
	}
	string ss = "";
	dfs(ss, count, len, _m);
	cout << ss << endl;
}
