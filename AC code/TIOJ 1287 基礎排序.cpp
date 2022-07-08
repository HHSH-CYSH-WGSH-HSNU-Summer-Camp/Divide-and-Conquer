#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void mergesort(int l, int r) {

	// 邊界條件：陣列長度等於 1
	if (l == r) return;

	// 遞迴排序左半邊跟右半邊
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);

	// 合併左右兩半邊
	vector<int> sorted;
	int Lptr = l, Rptr = mid+1;

	while (Lptr <= mid && Rptr <= r) {
		
		if (arr[Lptr] < arr[Rptr]) {
			sorted.push_back(arr[Lptr]);
			Lptr++;

		} else {
			sorted.push_back(arr[Rptr]);
			Rptr++;

		}

	}

	while (Lptr <= mid) {
		sorted.push_back(arr[Lptr]);
		Lptr++;
	}
	while (Rptr <= r) {
		sorted.push_back(arr[Rptr]);
		Rptr++;
	}

	for (int i = l, j = 0; i <= r; i++, j++) {
		arr[i] = sorted[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		arr.clear(); arr.resize(n);
		for (auto& i : arr) cin >> i;
		mergesort(0, n-1);
		for (auto& i : arr) cout << i << ' ';
		cout << endl;
	}

	return 0;
}