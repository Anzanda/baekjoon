#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio()
#define endl "\n"

using ll = long long;

const int MAX = 5*1e5;

int n;
int arr[MAX+5];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
	ll ans = 0;
	stack<int> s;
	for(int i=0; i<n; i++) {
		if(s.empty()) {
			s.push(arr[i]);
			continue;
		}
		if(s.top() < arr[i]) {
			ans += (ll)s.size();
			while(s.top() < arr[i]) {
				s.pop();
				if(s.empty()) {
					break;
				}
			}
			s.push(arr[i]);
		} else {
			ans += (ll)s.size();
			s.push(arr[i]);
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
