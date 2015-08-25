#include <iostream>
using namespace std;

int find(int n, long long int k) {
	long long int h = (1L << (n - 1));
	if(k == h) return 0;
	else if(k < h) return find(n - 1, k);
	else return !find(n - 1, (1L << n) - k);
}

int main() {
	int t;
	long long int k;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> k;
		int j = 63;
		for(; j > -1 && !((1L << j) & k); j--);
		cout << "Case #" << i << ": " << find(j + 1, k) << endl;
	}
}
