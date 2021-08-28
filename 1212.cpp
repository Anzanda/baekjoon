#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

string s;
void input() {
	cin >> s;
}
void printBinary(int n) {
	for(int i=2; i>=0; i--) {
		if(n&(1<<i)) {
			cout << 1;
		} else {
			cout << 0;
		}
	}
}
void solve() {
	int n = s[0]-'0';
	bool flag = false;
	for(int i=2; i>=0; i--) {
		if(n&(1<<i)) {
			cout << 1;
			flag = true;
		} else if(flag) {
			cout << 0;
		}
	}
	for(int i=1; i<s.length(); i++) {
		printBinary(s[i]-'0');
	}
	cout << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
