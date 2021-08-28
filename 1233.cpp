#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int s1, s2, s3;
map<int, int> m;
void input() {
	cin >> s1 >>s2 >> s3;
}
void solve() {
	for(int i=1; i<=s1; i++) {
		for(int j=1; j<=s2; j++) {
			for(int k=1; k<=s3; k++) {
				m[i+j+k]++;
			}
		}
	}
	int maxCount = -1;
	for(auto it=m.begin(); it!=m.end(); it++) {
		maxCount = max(maxCount, it->second);
	}
	for(auto it=m.begin(); it!=m.end(); it++) {
		if(it->second == maxCount) {
			cout << it->first << endl;
			return;
		}
	}
	return;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
