#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 50;

int n, m;
char castle[MAX][MAX];
bool row[MAX];
bool col[MAX];
void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> castle[i][j];
		}
	}
}
void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(castle[i][j] == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	int rowCount = 0;
	int colCount = 0;
	for(int i=0; i<n; i++) {
		if(!row[i])	rowCount++;
	}
	for(int i=0; i<m; i++) {
		if(!col[i])	colCount++;
	}
	cout << max(rowCount, colCount) << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
