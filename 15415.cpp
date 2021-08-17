#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll=long long int;

int W, N; 
int main(void) {
	cin >> W;
	cin >> N;
	ll ans = 0;
	for(int i=0; i<N; i++) {
		int w, l;
		cin >> w >> l;
		ans += w*l;
	}
	ans /= W;
	cout << ans << endl;
	return 0;
}
