#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;
int main (){
	cin >> x >> y >> w >> h;
	int ans = min(abs(x-w), abs(y-h));
	ans = min(abs(x), abs(y));
	cout << ans << endl;
	return 0;
}
