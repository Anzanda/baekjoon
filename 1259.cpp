#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

string str;
bool isPalinedrome() {
	int lf= 0;
	int rg = str.length()-1;
	while(lf < rg) {
		if(str[lf] != str[rg]) {
			return false;
		}
		lf++;
		rg--;
	}
	return true;
}
void solve() {
	while(true) {
		cin >> str;
		if(str[0] == '0'&& str.length() == 1) break;
		if(isPalinedrome()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
int main(void) {
	FastIO;
	solve();
	return 0;
}
