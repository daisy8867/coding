#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, i;
	cin >> n >> m;
	vector<int> a(n, 0);
	for(i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0, num;
	for(int nn : a) {
		if(!count) num = nn;
		count += (nn == num) ? 1 : -1;
	}
	for(i = 0, count = 0; i < n; i++) {
		if(a[i] == num) count++;
	}
	if(count > (a.size() / 2)) {
		cout << num << endl;
	}
	else {
		cout << "?" << endl;
	}
}
