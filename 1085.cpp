#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;
int main (){
	cin >> x >> y >> w >> h;
	x = min(x, abs(w-x));
	y = min(y, abs(h-y));
	ans = min(x, y);
	cout << ans << endl;
	return 0;
}
