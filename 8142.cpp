#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 1000;

int n;
int arr[MAX][MAX];
bool vst[MAX][MAX];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
}
int dr[] = {0, -1, -1, -1, 0, 1, 1, 1,};
int dc[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool isRange(int r, int c) {
	if(r < 0 || r > n-1 || c < 0 || c > n-1) {
		return false;
	}
	return true;
}
const int FAIL = -1;
const int NORMAL = 0;
const int VALLEY = 1;
const int RIDGE = 2;
int dfs(int r, int c) {
	vst[r][c] = true;
	int ret = NORMAL;
	for(int i=0; i<8; i++) {
		if(ret == FAIL) {
			return ret;
		}
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(isRange(nr, nc)) {
			if(arr[r][c] == arr[nr][nc]) {
				if(vst[nr][nc])	continue;
				if(ret == NORMAL) {
					ret = dfs(nr, nc);
				} else {
					int val = dfs(nr, nc);
					if(val != 0)	ret = val != ret? FAIL:ret;
				}
			} else {
				int val = arr[nr][nc]-arr[r][c] > 0 ? VALLEY:RIDGE;
				if(ret == NORMAL) {
					ret = val;
				} else {
					ret = val != ret? FAIL:ret;
				}
			}
		}
	}
	return ret;
}
void solve() {
	int valley = 0;
	int ridge = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!vst[i][j]) {
				int val = dfs(i, j);
				if(val == VALLEY) {
					valley++;
				}
				if(val == RIDGE) {
					ridge++;
				}
			}
		}
	}
	cout << ridge << " " << valley << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
