#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 10

int t;
int n, m;
char room[MAX][MAX];
int dp[MAX][1<<MAX];
// i: i'th row
// j: bitMask of student
bool isValid(int mask, int mask2) {
	for(int i=0; i<m; i++) {
		if(mask&(1<<i)) {
			for(int j=-1; j<=1; j++) {
				if(j == 0)	continue;
				int ni = i + j;
				if(ni < 0 || ni > m-1)	continue;
				if(mask&(1<<ni))	return false;
				if(mask2&(1<<ni))	return false;
			}
		}
	}
	return true;
}
bool isWall(int r, int mask) {
	for(int i=0; i<10; i++) {
		if(mask&(1<<i)) {
			if(room[r][i] == 'x')	return true;
		}
	}
	return false;
}
int main(void) {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> room[i][j];
			}
		}
		memset(dp, -1, sizeof dp);
		for(int mask=0; mask<(1<<m); mask++) {
			//dp[0][mask] initializing!
			if(!isValid(mask, mask))continue;
			if(isWall(0, mask))	continue;
			int numOfStudent = 0;
			for(int i=0; i<m; i++) {
				if(mask&(1<<i))	numOfStudent++;
			}
			dp[0][mask] = numOfStudent;
		}
		for(int i=1; i<n; i++) {
			for(int mask=0; mask<(1<<m); mask++) {
				if(!isValid(mask, mask))	continue;
				if(isWall(i, mask))	continue;
				for(int mask2=0; mask2<(1<<m); mask2++){
					if(isWall(i-1, mask2))	continue;
					if(isValid(mask, mask2)) {
						dp[i][mask] = max(dp[i][mask], dp[i-1][mask2]);
					}
				}
				for(int j=0; j<m; j++) {
					if(mask&(1<<j))	dp[i][mask]++;
				}
			}
		}
		int ans = -1;
		for(int mask=0; mask<(1<<m); mask++) {
			ans = max(ans, dp[n-1][mask]);
		}
		cout << ans << endl;
	}
	return 0;
}
