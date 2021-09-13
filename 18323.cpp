#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define pb push_back

const int MAX = 1e3;

int n;
int arr[MAX];
bool ans;
void input() {
	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin >> arr[i];
	}
}
void solvePermutation(vector<int> v, int idx) {
	if(ans)	return;
	if(idx == n-1) {
		if(!ans) {
			for(int i=0; i<(int)v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
			ans = true;
		}
		return;
	}
	int nxt = arr[idx] - v[idx];
	if(nxt <= 0)	return;
	for(int i=0; i<(int)v.size(); i++) {
		if(v[i] == nxt) {
			return;
		}
	}
	v.pb(nxt);
	solvePermutation(v, idx+1);
}
void solve() {
	for(int i=1; i<=arr[0]; i++) {
		vector<int> v;
		v.pb(i);
		solvePermutation(v, 0);
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
