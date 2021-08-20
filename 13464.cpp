#include <bits/stdc++.h>
using namespace std;

#define MAX 4000
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987654321

const int TIME_OUT = 1800;

int n;
int arr[MAX];
int dp[MAX];
void input() {
	FastIO;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
int rundp(int curr) {
	if(curr > n-1) {
		return 0;
	}
	int& ret = dp[curr];
	if(ret != -1) {
		return ret;
	}
	ret = INF;
	int tmp = 0;
	for(int i=curr; i<n; i++) {
		int diff = arr[i] - arr[curr];
		if(diff-tmp >= TIME_OUT) {
			tmp += diff-TIME_OUT-tmp;
		}
		tmp += 20;
		ret = min(ret, tmp+rundp(i+1));
	}
	return ret += 120;
}
void solve() {
	memset(dp, -1, sizeof dp);
	cout << rundp(0) << endl;
}
int main(void) {
	input();
	solve();
	return 0;
}
