#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
#define MAX 100007

int n;
int main(void) {
	FastIO;
	cin >> n;
	int num;
	int one, modOne, modTwo;
	one = modOne = modTwo = 0;
	for(int i=0; i<n; i++) {
		cin >> num;
		if(num == 1) {
			one++;
		} else if(num%3 == 1) {
			modOne++;
		} else if(num%3 == 2) {
			modTwo++;
		}
	}
	bool ans = false;
	if(one <= modTwo) {
		modTwo -= one;
		if(modTwo > modOne) {
			modTwo -= modOne;
			modOne = 0;
		} else {
			modOne -= modTwo;
			modTwo = 0;
		}
		if(modOne%3 == 0 && modTwo%3 == 0) {
			ans = true;
		}
	}
	if(ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
