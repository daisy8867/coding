//http://code-festival-2014-china.contest.atcoder.jp/tasks/code_festival_china_b
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int64; 

int main() {
	int n;
	int64 q, x, t;
	cin >> n;
	while(n--) {
		cin >> q;
		x = (int64)ceil(sqrt(2.0 * q - 1.0) * 0.5 - 0.5);
		t = 2 * (x - 1) * x + 1;
		q -= t;
		int tmp = -x + (q >> 1);
		if(tmp <= 0) {
			if(q & 1) {
				cout << -x + (q >> 1) << " " << (q >> 1) << endl;
			}
			else {
				cout << -x + (q >> 1) << " " << -(q >> 1) << endl;
			}
		}
		else {
			if(q & 1) {
				cout << -x + (q >> 1) << " " << (x << 1) - (q >> 1) << endl;
			}
			else {
				cout << -x + (q >> 1) << " " << (q >> 1) - (x << 1) << endl;
			}
		}
	}
	return 0;
}
