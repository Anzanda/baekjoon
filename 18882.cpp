#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define ff first
#define ss second
#define INF 987654321

using pii = pair<int,int>;

const int MAXN = 100;
const int MAXT = 250;

int t, n;
string infectRes;
pair<int, pii> arr[MAXT];
bool infect[MAXN+1];
int cnt[MAXN+1];
void input() {
	cin >> n >> t;
	cin >> infectRes;
	for(int i=0; i<t; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = {a, {b-1, c-1}};
	}
}
void solve() {
	sort(arr, arr+t);
	for(int i=0; i<n; i++) {
		if(infectRes[i] == '0')	continue;
		memset(infect, false, sizeof infect);
		memset(cnt, 0, sizeof cnt);
		int upper = INF;
		infect[i] = true;
		for(int j=0; j<t; j++) {
			pii curr = arr[j].ss;	
			if(infect[curr.ff] != infect[curr.ss]) {
				int a = curr.ff;
				int b = curr.ss;
				if(infect[b])	swap(a,b); // a가 감염임 무조건.
				if(cnt[a] >= upper)	continue;
				if(infectRes[b] == '0') {
					upper = min(upper, cnt[a]);
				} else {
					cnt[a]++;
					infect[b] = true;
				}
			} 
		}
		bool success = true;
		for(int i=0; i<n; i++) {
			if(infectRes[i] == '1') {
				if(infect[i] != true) {
					success = false;
				}
			} else {
				if(infect[i] != false) {
					success = false;
				}
			}
		}
		if(success) {
			if(upper == INF)
				cout << i+1 << " " <<  *max_element(cnt,cnt+n) << " Infinity" << endl;
			else
				cout << i+1 << " " << *max_element(cnt, cnt+n) << " " << upper << endl;
			return;
		}
	}
}
int main(void) {
	input();
	solve();
	return 0;
}
