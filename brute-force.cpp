#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int h[n];
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		// check the elements between i-th and j-th elements:
		// h[i], h[k], h[k + 1], ..., h[j] (x <= h[i], h[j])
		// if this sequence is true, then increment both the places of i and j
		int c[n] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (h[j] > h[i]) {
					break;
				}
				if (h[i] == h[j]) {
					c[i]++;
					c[j]++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << c[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
