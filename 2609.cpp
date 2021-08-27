#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int a, b;
int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
void input() {
	cin >> a >> b;
}
void solve() {
	int g = gcd(a, b);
	int m = a * b / g;
	cout << g << endl;
	cout << m << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
