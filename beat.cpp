#include <iostream>
#include <vector>
using namespace std;

long long int gcd(long long int a, long long int b) {
	if(a == b) {
		return b;
	}
	else {
		if(a < b) {
			long long int t = a; 
			a = b;
			b = t;
		}
		a -= b;
		return gcd(a, b);
	}
}
int main() {
	int n;
	long long int c;
	long long int b[100001];
	while(cin >> n >> c) {
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for(int i = 0; i < n; i++) {
			if(c >= b[i]) {
				c += b[i];
			}
			else {
				c += gcd(b[i], c);
			}
		}
		cout << c << endl;
	}
}
