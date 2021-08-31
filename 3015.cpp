#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio()
#define endl "\n"

const int MAX = 500000;

int n;
int arr[MAX+5];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
	int ans = 0;
	stack<int> s;
	for(int i=0; i<n; i++) {
		if(s.empty()) {
			s.push(arr[i]);
			continue;
		}
		if(s.top() < arr[i]) {
			ans += s.size();
			while(s.top() < arr[i]) {
				s.pop();
				if(s.empty()) {
					break;
				}
			}
			s.push(arr[i]);
		} else {
			ans += s.size();
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
