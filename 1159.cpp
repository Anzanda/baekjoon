#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int n;
map<char, int> m;
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		m[s[0]]++;
	}
}
void solve() {
	bool flag= false;
	for(auto it=m.begin(); it!=m.end(); it++) {
		if(it->second >= 5) {
			cout << it->first;
			flag = true;	
		}
	}
	if(!flag) {
		cout << "PREDAJA" << endl;
	}
	return;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
