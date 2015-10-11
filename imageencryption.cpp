#include <bits/stdc++.h>
using namespace std;

bool diff(vector<vector<int> >& a, vector<vector<int> >& b, int up, int left, int down, int right) {
	bool same = true;
	for(int i = up; i <= down && same; i++) {
		for(int j = left; j <= right && same; j++) {
			if(a[i][j] != b[i][j]) same = false;
		}
	}
	return same;
}

void rotate(vector<vector<int> >& a, int up, int left, int down, int right) {
	while(up < down) {
		int n = down - up;
		for(int i = 0; i < n; i++) {
			int tmp = a[up][left + i];
			a[up][left + i] = a[down - i][left];
			a[down - i][left] = a[down][right - i];
			a[down][right - i] = a[up + i][right];
			a[up + i][right] = tmp;
		}
		up++, down--, left++, right--;
	}
}

bool dfs(vector<vector<int> >& a, vector<vector<int> >& b, int up, int left, int down, int right) {
	bool same =	diff(a, b, up, left, down, right);
	if(same) {
		return true;
	}
	else if (((down - up) & 1) && up < down && dfs(a, b, up, left, (down + up) / 2, (left + right) / 2) 
			&& dfs(a, b, up, (left + right) / 2 + 1, (down + up) / 2, right)
			&& dfs(a, b, (down + up) / 2 + 1,  left, down, (left + right) / 2)
			&& dfs(a, b, (down + up) / 2 + 1, (left + right) / 2 + 1, down, right)) {
		return true;
	}
	else {
		for(int i = 0; i < 3; i++) {
			rotate(a, up, left, down, right);
			bool same =	diff(a, b, up, left, down, right);
			if(same) {
				return true;
			}
			else if (((down - up) & 1) && up < down && dfs(a, b, up, left, (down + up) / 2, (left + right) / 2) 
					&& dfs(a, b, up, (left + right) / 2 + 1, (down + up) / 2, right)
					&& dfs(a, b, (down + up) / 2 + 1,  left, down, (left + right) / 2)
					&& dfs(a, b, (down + up) / 2 + 1, (left + right) / 2 + 1, down, right)) {
				return true;
			}
		}
		return false;
	}
}

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<vector<int> > a(n, vector<int>(n, -1));
		vector<vector<int> > b(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> b[i][j];
			}
		}
		if(dfs(a, b, 0, 0, n - 1, n - 1)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
