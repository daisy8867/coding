#include <bits/stdc++.h>
using namespace std;

void prime(vector<bool>& pri) {
	int sz = pri.size();
	int sq = sqrt(sz);
	for(int i = 2; i <= sq; i++) {
		if(pri[i]) {
			for(int j = i + i; j < sz; j += i) {
				pri[j] = false;
			}
		}
	}
}

void factor(long long int n, vector<long long int>& f, vector<bool>& pri, int& l) {
//	cout << n << endl;	
	for(long long int i = 2; i * i <= n; i++) {
		if(!(n % i)) {
//			cout << i << " is a factor of " << n << endl;
			f[l++] = i;
			while(n && !(n % i)) {
				n /= i;
			}
		}
	}
	if(n > 1) {
//		cout << n << " is a factor of " << n << endl;
		f[l++] = n;
	}
//	cout << l << endl;
}

int dfs(int mask, vector<long long int>& f, vector<bool>& pri, vector<int>& dp, const long long int n, const int& l) {
//	cout << "checking " << mask << endl;
	if(dp[mask] > -1) return dp[mask];
	long long int tmp = n;
	for(int i = 0; i < l; i++) {
		if(mask & 1 << i) {
//			cout << "factor: " << f[i] << endl;
			while(!(tmp % f[i])) {
//				cout << "y: " << tmp  << " factor: " << f[i] << endl;	
				tmp /= f[i];
			}
		}
	}
//	cout << "y: " << tmp << endl;	
	int s = 0, y = 10;
	while(tmp) {
		s += (tmp % y);
		tmp /= y;
	}
//	cout << s << endl;
	if(pri[s]) {
//		cout << s << " is prime" << endl;
		return dp[mask] = 0;
	}
//	cout << l << endl;
	for(int i = 0; i < l; i++) {
		if(!(mask & (1 << i))) {
//			cout << "x: " << mask << ", i: " << i << endl;
			if(!dfs((mask | (1 << i)), f, pri, dp, n, l)) {
				return dp[mask] = 1;
			}
		}
	}
	return dp[mask] = 0;
}

int main() {
	const int _con = 200;
	vector<bool> pri(_con, true);
	prime(pri);
	int t, l;
	long long int n;
	vector<long long int> f((1 << 16), 0);
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> n;
		vector<int> dp((1 << 16), -1);
		l = 0;
		factor(n, f, pri, l);
		int ret = dfs(0, f, pri, dp, n, l);
		string res = (ret) ? "Laurence" : "Seymour";
		cout << "Case #" << i << ": " << res << endl;
	}
}
