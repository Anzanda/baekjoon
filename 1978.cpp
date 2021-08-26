#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 1024;

int n;
bool prime[MAX];
int arr[128];
int ans;
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void initPrime() {
	memset(prime, true, sizeof prime);
	prime[0] = prime[1] = false;
	for(int i=2; i<=sqrt(MAX); i++) {
		if(!prime[i])	continue;
		for(int j=i*i; j<MAX; j+=i) {
			prime[j] = false;
		}
	}
}
void solve() {
	initPrime();
	for(int i=0; i<n; i++) {
		ans += prime[arr[i]];
	}
	cout << ans << endl;
}
int main(void) {
//	FastIO;
	input();
	solve();
	return 0;
}
