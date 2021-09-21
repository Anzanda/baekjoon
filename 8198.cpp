#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

using ll = long long;

const int MX = 1e6;

int n, k;
ll m;
ll a[MX];
int jmp[MX];
void input() {
	cin >> n >> k;
	cin >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
}
ll getDist(ll a, ll b) {
	return abs(a-b);
}
void getJmp() {
	int l = 0;
	int r = k;
	for(int i=0; i<n; i++) {
		while(r+1<n && getDist(a[i], a[l])>getDist(a[i], a[r+1])) {
			l++;
			r++;
		}
		if(getDist(a[i],a[l]) < getDist(a[i], a[r])) {
			jmp[i] = r;
		} else {
			jmp[i] = l;
		}
	}
}
int ans[MX];
int tmp[MX];
void solve() {
	iota(ans, ans+n, 0);
	while(m) {
		if(m&1) {
			for(int i=0; i<n; i++) {
				ans[i] = jmp[ans[i]];
			}
		}
		for(int i=0; i<n; i++) {
			tmp[i] = jmp[jmp[i]];
		}
		for(int i=0; i<n; i++) {
			jmp[i] = tmp[i];
		}
		m >>= 1;
	}
}
void printAnswer() {
	for(int i=0; i<n; i++)	cout << ans[i] +  1 << " ";
	cout << endl;
}
int main(void) {
	FastIO;
	input();
	getJmp();
	solve();
	printAnswer();
	return 0;
}
