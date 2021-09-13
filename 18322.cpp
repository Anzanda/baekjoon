#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 100;

int n, k;
string arr[MAX];
void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
	int currCnt = 0;
	for(int i=0; i<n; i++) {
		if(currCnt + (int)arr[i].size() > k) {
			cout << endl;
			cout << arr[i] << " ";
			currCnt = (int)arr[i].size();	
		} else {
			cout << arr[i] << " ";
			currCnt += (int)arr[i].size();
		}
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
