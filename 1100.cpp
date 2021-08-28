#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int ans;
char chess[8][8];
void input() {
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			cin >> chess[i][j];
		}
	}
}
void solve() {
	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if((i+j)%2)	continue;
			if(chess[i][j] == 'F') {
				ans++;
			}
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
