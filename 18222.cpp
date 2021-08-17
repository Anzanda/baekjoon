#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll=long long;

ll k;
int finalBit[64];
int solve(ll input) {
	int ret;
	bool reverseFlag = false;
	for(ll i=63; i>=0; i--) {
		if(input&(1LL<<i)) {
			if(reverseFlag) {
				ret = finalBit[i]? 0:1;
				reverseFlag = false;
			} else {
				ret  = finalBit[i];
				reverseFlag = true;
			}
		}
	}
	return ret;
}
int main(void) {
	cin >> k;
	for(int i=0; i<64; i++) {
		finalBit[i] = i%2;
	}
	cout << solve(k) << endl;
	return 0;
}
