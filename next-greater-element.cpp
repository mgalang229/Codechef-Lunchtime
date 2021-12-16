#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9 + 7;

int* NextGreater(int h[], int n) {
	stack<pair<int, int>> st;
	st.push(make_pair(inf, 0));
	int *ans = new int[n];
	for (int i = 0; i < n; i++) {
		ans[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		// remove the top of the stack until it is greater than or equal
		// to the current element being iterated upon
		while (st.top().first < h[i]) {
			st.pop();
		}
		// if the current element is not equal to the top of the stack,
		// then simply initialize its frequency to 0
		if (st.top().first != h[i]) {
			st.push(make_pair(h[i], 0));
		}
		// store the frequency of the top of the stack in the array
		ans[i] = st.top().second;
		// increase the frequency of the element at the top of the stack
		st.top().second++;
	}
	return ans;
}

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
		// use the principle of Next Greater Element (Stack)
		// checking for same numbers at the left of each element
		int* left = NextGreater(h, n);
		reverse(h, h + n);
		// checking for the same numbers at the right of each element
		int* right = NextGreater(h, n);
		reverse(right, right + n);
		// add the values collected from the left and right side
		for (int i = 0; i < n; i++) {
			cout << left[i] + right[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
