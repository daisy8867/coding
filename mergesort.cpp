#include "header.h"
void merge(vector<int>& v, int start, int end, int mid) {
	vector<int> tmp(end - start + 1);
	int t = 0, f = start, s = mid + 1;
	for(f = start, s = mid + 1; f <= mid && s <= end; ) {		
		if(v[f] < v[s]) {
			tmp[t++] = v[f++];
		}
		else {
			tmp[t++] = v[s++];
		}
	}
	while(f <= mid) {
		tmp[t++] = v[f++];
	}
	while(s <= end) {
		tmp[t++] = v[s++];
	}
	for(int i = start, t = 0; i <= end;) {
		v[i++] = tmp[t++];
	}
}
void mergesort(vector<int>& v) {
	int len = v.size();
	int stride = 2;
	for(stride = 2; stride < len; stride <<= 1) {
		for(int start = 0; start < len; start += stride) {
			int right = min(start + stride - 1, len - 1);
			int mid = (start >> 1) + (right >> 1); 
			merge(v, start, right, mid);
//			for(int i = 0; i < len; i++) {
//				cout << v[i] << " ";
//			}
//			cout << endl;
		}
	}
	merge(v, 0, len - 1, (stride >> 1) - 1);
}
int main() {
	int n = 17;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		v.emplace_back(n - i);
	}
	mergesort(v);
	for(int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}
