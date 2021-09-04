#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

struct cmp {
	bool operator()(const string& a, const string& b) {
		if(a.length() != b.length()) {
			return	a.length() < b.length();
		}
		return a < b;
	}
};
int n;
set<string, cmp> s;
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
}
void solve() {
	for(auto it=s.begin(); it!=s.end(); it++) {
		cout << *it << endl;
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
