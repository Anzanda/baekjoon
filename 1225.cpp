#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

using ll = long long;

ll ans;
string A, B;
void input() {
	cin >> A >> B;
}
void solve() {
	for(int i=0; i<(int)A.length(); i++) {
		for(int j=0; j<(int)B.length(); j++) {
			ans += (A[i]-'0')*(B[j]-'0');
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
