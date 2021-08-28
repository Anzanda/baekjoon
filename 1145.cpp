#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int arr[5];
void input() {
	for(int i=0; i<5; i++) {
		cin >> arr[i];
	}
}
void solve() {
	int ans = 1;
	while(true) {
		int cnt = 0;
		for(int i=0; i<5; i++) {
			if(ans%arr[i] == 0) {
				cnt++;
			}
		}
		if(cnt >= 3) {
			break;
		}
		ans++;
	}
	cout << ans << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
