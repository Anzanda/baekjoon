#include <bits/stdc++.h>
using namespace std;

#define MAX 1e+5
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"

int n;
map<string, int> DOMjudge;
map<string, int> Kattis;
void input() {
	cin >> n;
	string result;
	for(int i=0; i<n; i++) {
		cin >> result;
		DOMjudge[result]++;
	}
	for(int i=0; i<n; i++) {
		cin >> result;
		Kattis[result]++;
	}
}
int solve() {
	int ret=0;
	for(auto it=DOMjudge.begin(); it!=DOMjudge.end(); it++) {
		ret += min(DOMjudge[it->first], Kattis[it->first]);
	}
	return ret;
}
int main(void) {
	FastIO;
	input();
	cout << solve() << endl;
	return 0;
}
