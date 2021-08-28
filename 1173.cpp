#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int N, m, M, T, R;
void input() {
	cin >> N >> m >> M >> T >> R;
}
void solve() {
	int ans = 0;
	int X = m;
	if(X + T > M) {
		cout << -1 << endl;
		return;
	}
	while(N) {
		if(X + T > M ) {
			X -= R;
			if(X < m) {
				X = m;
			}
			ans++;
		} else {
			X += T;
			N--;
			ans ++;
		}
	}
	cout << ans << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
