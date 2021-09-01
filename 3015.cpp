#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio()
#define endl "\n"
#define ff first
#define ss second

using ll = long long;
using pii = pair<int,int>;

const int MAX = 5*1e5;

int n;
int arr[MAX+5];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
}
void solve() {
    ll ans = 0;
    stack<pii> s;
    for(int i=0; i<n; i++) {
        if(s.empty()) {
            s.push({arr[i], 1});
            continue;
        }
        if(s.top().ff < arr[i]) {
            while(s.top().ff < arr[i]) {
                ans += s.top().ss;
                s.pop();
                if(s.empty()) { // 나만의 가독성을 위해ㅋㅋ;
                    break;
                }
            }
            i--; // top() <= arr[i]상태로 만들고 i로 다시 for문기돌리기
        } else if(s.top().ff == arr[i]){
            ans += s.top().ss;
            s.top().ss++;
            if(s.size() > 1) {
                ans++;
            }
        } else {
            s.push({arr[i], 1});
            ans++;
        }
    }
    cout << ans << endl;
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
