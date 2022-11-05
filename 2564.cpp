#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
using pii = pair<int,int>;

// 맞은 편 아니면, 그냥 가면됨.
// 맞은 편이면 한 쪽만 구하고 둘레 - 한쪽 중에 큰 거를 취함.
// 맞은 편 == 서로 차가 1임.

const int MX = 1e2+5;

int a, b;
int aabb;
int n;
pii stores[MX];
pii me;
int solve_front(pii store);
int solve_by(pii store);
int solve(pii store) {
	if(store.ff == 1 && me.ff == 2) {
		return solve_front(store);
	} else if(store.ff == 2 && me.ff == 1) {
		return solve_front(store);
	} else if(store.ff == 3 && me.ff == 4) {
		return solve_front(store);
	} else if(store.ff == 4 && me.ff == 3) {
		return solve_front(store);
	} else if(abs(store.ff - me.ff) != 0){
		return solve_by(store);
	} else {
		return abs(store.ss - me.ss);
	}
}
int solve_front(pii store) {
	int circle = me.ss + store.ss;
	if(me.ff == 1 || me.ff == 2) {
		circle += b;
	} else {
		circle += a;
	}
	return min(circle, aabb - circle);
}
int solve_by(pii store) {
	int result = 0;
	if(me.ff == 1) {
		if(store.ff == 3) {
			result += me.ss;
			result += store.ss;
		} else {
			result += (a - me.ss);
			result += (store.ss);
		}
	} else if(me.ff == 2) {
		if(store.ff == 3) {
			result += me.ss;
			result += (b-store.ss);
		} else {
			result += (a-me.ss);
			result += (b-store.ss);
		}
	} else if(me.ff == 3) {
		if(store.ff == 1) {
			result += me.ff;
			result += store.ss;
		} else {
			result += (b-me.ff);
			result += (store.ss);
		}
	} else {
		if(store.ff == 1) {
			result += me.ss;
			result += (a-store.ss);
		} else {
			result += (b-me.ss);
			result += (a-store.ss);
		}
	}
	return result;
}
int main(void) {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	aabb = a + a + b + b;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> stores[i].first >> stores[i].second;
	}
	cin >> me.ff >> me.ss;

	int ans = 0;
	for(int i=1; i<=n; i++) {
		ans += solve(stores[i]);
	}
	cout << ans << endl;
}