#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define ff first
#define ss second

using pi = pair<int,int>;

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
pi bfs(int r, int c) {
	int valley = 0;
	int ridge = 0;
	vst[r][c] = true;
	queue<pi> q;
	q.push({r,c});
	while(!q.empty()) {
		pi t = q.front();	q.pop();
		for(int i=0; i<8; i++) {
			int nr = t.ff + dr[i];
			int nc = t.ss + dc[i];
			if(!isRange(nr, nc))	continue;
			if(!vst[nr][nc] && arr[t.ff][t.ss] == arr[nr][nc]) {
				vst[nr][nc] = true;
				q.push({nr, nc});
			} else {
				valley += arr[t.ff][t.ss]<arr[nr][nc];	
				ridge += arr[t.ff][t.ss]>arr[nr][nc];
			}
		}
	}
	int retRidge = !valley&&ridge;
	int retValley = !ridge&&valley; 	
	return {retRidge, retValley};
}
void solve() {
	pi ans = {0 ,0};
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!vst[i][j]) {
				pi res = bfs(i, j);
				ans.ff += res.ff;
				ans.ss += res.ss;
			}
		}
	}
	if(!ans.ff&&!ans.ss) {
		ans.ff = ans.ss = 1;
	}
	cout << ans.ff << " " << ans.ss << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
