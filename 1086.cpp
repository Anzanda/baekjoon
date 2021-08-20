#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 15

using ll = long long int;

int n;
int k;
ll  dp[(1<<MAX)][100];
bool vst[(1<<MAX)];
string arr[MAX];
int arrMod[MAX];
int digitMod[51];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cin >> k;
}
void getDigitMods() {
	digitMod[0] = 1%k;
	for(int i=1; i<51; i++) {
		digitMod[i] = (digitMod[i-1]*10)%k;
	}
}
int getArrMod(string s) {
	int mod = 0;
	int digitCount = 0;
	for(auto it=s.rbegin(); it!=s.rend(); it++) {
		int tmp = *it-'0';
		tmp *= digitMod[digitCount];
		tmp %= k;
		mod += tmp;
		mod %= k;
		digitCount++;
	}
	return mod;
}
void getMods() {
	getDigitMods();
	for(int i=0; i<n; i++) {
		arrMod[i] = getArrMod(arr[i]);
	}
}
void printMask(int mask) {
	for(int i=0; i<n; i++) {
		cout << (mask&(1<<i)?1:0);
	}
	cout << endl;
}
int calculateMod(int mask, int curr) {
	int mod = arrMod[curr]; 
	for(int i=0; i<n; i++) {
		if(mask&(1<<i)) {
			mod *= digitMod[arr[i].length()];
			mod %= k;
		}
	}
	return mod;
}
void rundp(int mask) {
	if(vst[mask]) {
		return;
	}
	vst[mask] = true;
	if(mask == 0) {
		return;
	}
	for(int i=0; i<n; i++) {
		if(mask&(1<<i)) {
			int maskWithoutCurr = mask&~(1<<i);
			int mod = calculateMod(maskWithoutCurr, i);
			rundp(maskWithoutCurr);
			for(int j=0; j<k; j++) {
				dp[mask][(j+mod)%k] += dp[maskWithoutCurr][j];
			}
			if(maskWithoutCurr == 0) {
				dp[mask][mod] = 1;
			}
		}
	}
}
ll factorial(ll curr) {
	if(curr == 0) {
		return 1;
	}
	return curr*factorial(curr-1);
}
ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}
void solve() {
	int fullMask = (1<<n)-1;
	rundp(fullMask);
	ll divide = gcd(dp[fullMask][0], factorial(n));
	cout << dp[fullMask][0]/divide << "/" << factorial(n)/divide << endl;
}
int main(void) {
	FastIO;
	input();
	getMods();
	solve();
	return 0;
}
