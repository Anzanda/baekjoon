#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using ll=long long;

ll k;
int finalBit[64];
int main(void) {
	cin >> k;
	for(int i=0; i<64; i++) {
		finalBit[i] = i%2;
	}
	int ans;
	bool reverseFlag = false;
	for(int i=64; i>=0; i--) {
		if(k&(1<<i)) {
			if(reverseFlag) {
				ans = finalBit[i]? 0:1;
				reverseFlag = false;
			} else {
				ans = finalBit[i];
				reverseFlag = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
