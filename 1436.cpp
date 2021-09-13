#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int n;
void input() {
	cin >> n;
}
void solve() {
	int num = 666;
	while(n) {
		int tmp = num;
		int continuous= 0;
		while(tmp) {
			if(tmp%10 == 6) {
				continuous++;
			} else {
				if(continuous >= 3) {
					break;	
				}
				continuous = 0;
			}
			tmp /= 10;
		}
		if(continuous >= 3) {
			n--;
		}
		num++;
	}
	cout << num - 1 << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
