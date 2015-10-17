#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<int> fac(12, 1);
	for(int i = 1; i < 12; i++) {
		fac[i] = fac[i - 1] * i;
	}
	map<char, int> mp;
	for(int i = 0; i < 12; i++) {
		mp[i + 'a'] = i;
	}
	int n, m;
	string s;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s;
		vector<int> less(12, 0);
		for(int j = 0; j < 12; j++) {
			less[j] = mp[s[j]];
			for(int k = 0; k < j; k++) {
				if(s[k] < s[j]) less[j]--;
			}
		}
		for(int j = 0; j < 12; j++) {
			cout << less[j] << " ";
		}
		cout << endl;
		m = 0;
		for(int j = 0; j < 12; j++) {
//			cout << (mp[s[j]] - less[j]) << endl;
//			cout << fac[11 - j] << endl;
			m += less[j] * fac[11 - j];
		}
		cout << m + 1 << endl;
	}
}
