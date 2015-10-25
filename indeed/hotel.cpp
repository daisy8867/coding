#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i, j;
	cin >> n >> m;
	vector<int> a(n, 0);
	vector<int> b(m, 0);
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(i = 0; i < m; i++) {
		cin >> b[i];
	}
	if(n < m) cout << "NO" << endl;
	else {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(i = n - 1, j = m - 1; j > -1 && a[i] >= b[j]; i--, j--);
		if(j == -1) {
			cout << "YES" << endl;
		}
		else {
		   	cout << "NO" << endl;
		}
	}
}
