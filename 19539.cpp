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
	int modTwo = 0;
	int sum = 0;
	for(int i=0; i<n; i++) {
		cin >> num;
		sum += num;
		modTwo += num/2;
	}
	bool ans = false;
	if(sum%3 == 0) {
		int three = sum/3;
		if(three <= modTwo) {
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
