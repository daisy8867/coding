#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
	int t;
	double a[1000];
	cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m;
		cin >> n >> m;
		for(int j = 0; j < n; j++) {
			cin >> a[j];
			a[j] = log10(a[j]);
		}
		printf("Case #%d:\n", i);
		while(m--) {
			int l, r;
			cin >> l >> r;
			double d = r - l + 1;
			double v = 0.0;
			for(int j = l; j <= r; j++)	{
				v += a[j];
			}
			v /= d;
			printf("%.9lf\n", pow((double)10, v));
		}
	}
}
