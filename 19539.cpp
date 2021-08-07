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
	int modOne, modTwo;
	modOne = modTwo = 0;
	for(int i=0; i<n; i++) {
		cin >> num;
		if(num%3 == 1) {
			modOne++;
		} else if(num%3 == 2) {
			modTwo++;
		}
	}
	bool ans = modOne%3 == modTwo%3;
	if(ans) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
