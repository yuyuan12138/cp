#include <bits/stdc++.h>

void mergeSort(std::vector<int>& v, int l, int r) {
	if (l + 1 == r) {
		return ;
	}
	int mid = (l + r) >> 1;
	mergeSort(v, l, mid);
	mergeSort(v, mid, r);
	std::vector<int> nv(r - l);
	int cur1 = l, cur2 = mid;
	for (int i = 0; i < r - l; i++) {
		if (cur2 >= r || (cur1 < mid && v[cur1] <= v[cur2])) {
			nv[i] = v[cur1];
			cur1++;
		} else {
			nv[i] = v[cur2];
			cur2++;
		}
	}
	for (int i = 0; i < r - l; i++) {
		v[i + l] = nv[i];
	}
	return ;
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		mergeSort(a, 0, n);
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << ' ';
		}	
	}
	
}