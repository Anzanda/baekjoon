#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int n;
int f;
void input() {
	cin >> n;
	cin >> f;
}
void solve() {
	n = n - n%100;
	int i;
	for(i=0; i<100; i++) {
		if((n+i)%f == 0) {
			break;
		}
	}
	if(i < 10) {
		cout << 0 << i << endl;
	} else {
		cout << i << endl;
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
