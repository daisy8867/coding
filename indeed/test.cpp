#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {1, 2, 3};
	auto lb = lower_bound(a.begin(), a.end(), 4);
	cout << (lb == a.end()) << endl;
}
