#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

map<int, bool> m;
int _f[10];
int _s[10];
void input() {
	for(int i=0; i<10; i++) {
		cin >> _f[i];
	}
	for(int i=0; i<10; i++) {
		cin >> _s[i];
	}
}
void run(int n, int *f, int *s, int c) {
	if(n == 4) {
		m[c] = true;
		return;
	}
	if(n%2 == 0) {
		int *ff = (int*)malloc(sizeof(int)*9);
		int *ss = (int*)malloc(sizeof(int)*11);
		memcpy(ss, s, sizeof(int)*10);
		for(int i=0; i<10; i++) {
			ss[10] = f[i];	
			int idx = 0;
			for(int j=0; j<10; j++) {
				if(j == i)	continue;
				ff[idx++] = f[j];
			}
			run(n+1, ff, ss, c-f[i]);
		}
	} else {
		int *ff = (int*)malloc(sizeof(int)*10);
		int *ss = (int*)malloc(sizeof(int)*10);
		memcpy(ff, f, sizeof(int)*9);
		for(int i=0; i<11; i++) {
			ff[9] = s[i];
			int idx = 0;
			for(int j=0; j<11; j++) {
				if(j == i)	continue;
				ss[idx++] = s[j];
			}
			run(n+1, ff, ss, c+s[i]);
		}
	}
}
void solve() {
	run(0, _f, _s, 1000);	
	for(auto it=m.begin(); it!=m.end(); it++) {
		cout << it->first << endl;
	}
}
int main(void) {
	input();
	solve();
	return 0;
}
