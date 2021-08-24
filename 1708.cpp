#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define MAX 100000

using ll = long long;

const int COUNTER_CLOCK_WISE = 1;
const int STRAIGHT = 0;
const int CLOCK_WISE = -1;

struct Point {
	int x, y;
	int p, q;
	Point(int x = 0, int y = 0) 
		: x(x), y(y), p(1), q(0) {}
	bool operator <(const Point& a) {
		if (1LL * q * a.p != 1LL * p * a.q)
			return 1LL * q * a.p < 1LL * p * a.q;
		if(y != a.y)
			return y < a.y;

		return x < a.x;
	}
};

int ccw(const Point &A, const Point &B, const Point &C) {
	ll lf = 1LL * (B.x - A.x)*(C.y - A.y);
	ll rg = 1LL * (B.y - A.y)*(C.x - A.x);
	if (lf - rg > 0) {
		return COUNTER_CLOCK_WISE;
	} else if(lf - rg < 0) {
		return CLOCK_WISE;
	} else {
		return STRAIGHT;
	}
}
int n;
Point p[MAX];
void input() {
	cin >> n;
	int x, y;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		p[i] = Point(x, y);
	}
}

void start() {
	input();
	sort(p, p+n);
	for(int i=1; i<n; i++) {
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p+1, p+n);
}
void solve() {
	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	while (next < n) {
		while(s.size() >= 2) {
			int first, second;
			first = s.top();
			s.pop();
			second = s.top();
			if(ccw(p[second], p[first], p[next]) == COUNTER_CLOCK_WISE) {
					s.push(first);
					break;
			}
		}
		s.push(next++);
	}
	cout << s.size() << endl;
}
int main(void) {
	FastIO;
	start();
	solve();
	return 0;
}
