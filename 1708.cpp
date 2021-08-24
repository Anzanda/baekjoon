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
	Point(int x = 0, int y = 0, int p = 1, int q = 0) 
		: x(x), y(y), p(p), q(q) {}
	bool operator <(const Point& a) {
		if (1LL * q * a.p != 1LL * p * a.q)
			return 1LL * q * a.p < 1LL * p * a.q;
		if(y != a.y)
			return y < a.y;

		return x < a.x;
	}
};

ll ccw(const Point &A, const Point &B, const Point &C) {
	ll lf = 1LL * (A.x * B.y + B.x * C.y + C.x * A.y);
	ll rg = 1LL * (B.x * A.y + C.x * B.y + A.x * C.y);
	return lf - rg;
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
	sort(p, p+n);
}
void solve() {
	stack<int> s;
	s.push(0);
	s.push(1);
	int next = 2;
	while (next < n) {
		while(s.size() >= 2) {
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();
			if(ccw(p[first], p[second], p[next]) > 0) {
					s.push(second);
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
