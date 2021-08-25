#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

using ll=long long;

const int COUNTER_CLOCK_WISE = 1;
const int STRAIGHT = 0;
const int CLOCK_WISE= -1;

struct Point{
	int x, y;
	Point(int x=0, int y=0)
		:x(x), y(y) {}
	int ccw(Point ff, Point ss) {
		ll lf = 1LL*(ff.y-ss.y)*(x-ff.x);
		ll rg = 1LL*(ff.x-ss.x)*(y-ff.y);
		if(lf - rg > 0) {
			return COUNTER_CLOCK_WISE;
		} else if(lf - rg < 0) {
			return CLOCK_WISE;
		} else {
			return STRAIGHT;
		}
	}
};
Point A,B,C;	
void input() {
	int x, y;
	cin >> x >> y;
	A = Point(x, y);
	cin >> x >> y;
	B = Point(x, y);
	cin >> x >> y;
	C = Point(x, y);
}
void solve() {
	cout << A.ccw(B,C) << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}

