#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

using ll = long long;

const int MAX = 50;

int n;
ll arr[MAX];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
	sort(arr, arr+n);
	cout << arr[0] * arr[n-1] << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
