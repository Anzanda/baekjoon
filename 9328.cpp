#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 100

int T;
int h, w;
char field[MAXN][MAXN];
bool possible[MAXN][MAXN];
bool vst[MAXN][MAXN];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int ans;
bool isRange(int r, int c) {
	if(r < 0 || r > h-1 || c < 0 || c > w-1) {
		return false;
	}
	return true;
}
bool isUpper(int r, int c) {
	if(field[r][c] >= 'A' && field[r][c] <= 'Z') {
		return true;
	}
	return false;
}
bool isLower(int r, int c) {
	if(field[r][c] >= 'a' && field[r][c] <= 'z') {
		return true;
	}
	return false;
}
char transChar(int r, int c) {
	if(isUpper(r,c)) {
		return field[r][c] - 'A' + 'a';
	} else {
		return field[r][c] - 'a' + 'A';
	}
}
set<char> key;
set<pair<int,int>> pos;
void solve(int r, int c) {
	if(!isRange(r, c)) {
		return;
	}
	if(possible[r][c]) {
		return;
	}
	if(field[r][c] == '*') {
		return;
	}
	possible[r][c] = true;
	if(isUpper(r,c)) {
		return;
	} else if(field[r][c] == '$') {
		ans++;
	} else if(isLower(r,c)) {
		key.insert(field[r][c]);
	} 
	for(int i=0; i<4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		solve(nr, nc);
	}
}
void init() {
	for(int i=0; i<h; i++) {
		solve(i, 0);
		solve(i, w-1);
	}
	for(int i=0; i<w; i++) {
		solve(0, i);
		solve(h-1 ,i);
	}
}
int main(void) {
	FastIO;
	cin >> T;
	while(T--) {
		memset(field, 0, sizeof field);
		memset(possible, false, sizeof possible);
		memset(vst, false, sizeof vst);
		ans = 0;
		cin >> h >> w;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin >> field[i][j];
				if(isUpper(i, j)) {
					pos.insert({i,j});
				}
			}
		}
		string k;
		cin >> k;
		for(auto el: k) {
			key.insert(el);
		}
		init();
		bool flag = true;
		while(flag) {
			flag = false;
			for(auto it = pos.begin(); it != pos.end(); it++) {
				if(possible[it->first][it->second] && (key.find(transChar(it->first,it->second)) != key.end())) {
					if(vst[it->first][it->second])	continue;
					// cout << "HELLO " << endl;
					for(int i=0; i<4; i++) {
						int nr = it->first + dr[i];
						int nc = it->second + dc[i];
						solve(nr, nc);
					}
					vst[it->first][it->second] = true;
					// pos.erase(it);
					flag = true;
				}
			}
		}
		cout << ans << endl;
		key.clear();	set<char>().swap(key);
		pos.clear();	set<pair<int,int>>().swap(pos);
	}
}