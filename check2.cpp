#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MX = 1e5+5;

int n, k;
int a[MX];
int cycle[51];
void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
}
void solve() {
	for(int i=0; i<n; i++) {
		cycle[i%k] += a[i];
	}
	int max_value = -1;
	int max_idx = -1;
	for(int i=0; i<k; i++) {
		if(max_value < cycle[i]) {
			max_value = cycle[i];
			max_idx = i;
		}
	}
	cout << max_idx+1 << " " << max_value << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}	
