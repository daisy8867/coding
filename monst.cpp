#include <iostream> 
#include <numeric>
#include <algorithm>
#include <vector> 
#include <limits.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return ((double)a.second / (double)a.first) > ((double)b.second / (double)b.first);
}

long long permute(vector<pair<int, int> >& y, int debug = 0) {
    int sz = y.size();
    int *permute = (int *)malloc(sz * sizeof(int));
    iota (permute, permute + sz, 0);
    vector<int> candi(sz, 0);
//    int *permute = (int *)malloc(sz * sizeof(int));
//    itoa (permute, permute + sz, 0);
    long long res = INT_MAX;
    do {
        long long sum = 0, hurt = 0;
        for(int i = 0; i < sz; i++) {
    	    hurt += y[permute[i]].first;
    	    sum += hurt * y[permute[i]].second;
        }
	if(sum < res) {
	    res = sum;
	    for(int i = 0; i < sz; i++) {
		candi[i] = permute[i];
	    }
	}
    } while(next_permutation(permute, permute + sz));
    if(debug) {
	cout << "permute seq: ";
	for(int i = 0; i < sz; i++) {
	    cout << candi[i] << " ";
	}
	cout << endl;
    }
    return res;
}

long long mulgreedy(vector<pair<int, int> >& y) {
    sort(y.begin(), y.end(), [](const pair<int, int>& a, pair<int, int>& b){
	    return a.second * b.first > a.first * b.second;
	    });
    long long sum = 0, hurt = 0;
    for(auto p : y) {
	hurt += p.first;
	sum += hurt * p.second;
    }
    return sum;
}

long long greedy(vector<pair<int, int> >& y) {
    sort(y.begin(), y.end(), cmp);
    long long sum = 0, hurt = 0;
    for(auto p : y) {
	hurt += p.first;
	sum += hurt * p.second;
    }
    return sum;
}
int main() {
    int t = 1, n = 8, l, d;
    const int _max = 1000;
    while(t) {
        vector<pair<int, int> > y;
        for(int j = 0; j < n; j++) {
	    l = rand() % 1000 + 1;
	    d = rand() % 1000 + 1;
            y.push_back(make_pair(l, d));
        }   
	long long r1 = greedy(y);
	long long r2 = mulgreedy(y);
	long long r3 = permute(y);
	if(r1 != r2 || r2 != r3) {
	    t = 0;
	    cout << "wrong case: " << endl;
            for(int j = 0; j < n; j++) {
                cout << y[j].first << ", " << y[j].second << endl;
            }
	    cout << "divede greedy ans: " << r1 << endl;
	    cout << "permute greedy ans: " << r3 << endl;
	    cout << "multiply greedy ans: " << r2 << endl;
	    permute(y, 1);
	}
    }
//    cin >> t;
//    for(int i = 0; i < t; i++) {
//        cin >> n;
//        vector<pair<int, int> > y;
//        for(int j = 0; j < n; j++) {
//            cin >> l >> d;
//            y.push_back(make_pair(l, d));
//        }   
//        sort(y.begin(), y.end(), cmp);
////      for(int j = 0; j < n; j++) {
////          cout << y[j].first << ", " << y[j].second << endl;
////      }
//        int sum = 0, hurt = 0;
//        for(int j = 0; j < n; j++) {
//            hurt += y[j].first;
//            sum += hurt * y[j].second;
//        }   
//        cout << sum << endl;
//    }   
}
