#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	int n, d;
	double x;
	while(cin >> n) {
		x = (-1.0 + sqrt(1.0 + 8 * (n + 1)))/ 2.0;
		d = (int) ceil(x);
		cout << n - 2 * (d - 2) << endl;
	}
}
