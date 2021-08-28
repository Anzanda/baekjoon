#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 50;

int n, len;
string arr[MAX];
bool ans[MAX];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	len = arr[0].length();	
}
void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<len; k++) {
				if(arr[i][k] != arr[j][k]) {
					ans[k] = true;
				}
			}
		}
	}
	for(int i=0; i<len; i++) {
		if(ans[i]) {
			cout << "?";
		} else {
			cout << arr[0][i];
		}
	}
	cout << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
