#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define pb push_back

const int MAX = 10000;

int v, e;
vector<int> adj[MAX+1];
bool vst[MAX+1];
int num[MAX+1];
int low[MAX+1];
stack<int> s;
vector<vector<int>> ans;
int cnt = 0;
void dfs(int curr) {
	vst[curr] = true;
	num[curr] = ++cnt;
	low[curr] = cnt;
	s.push(curr);
	for(auto there: adj[curr]) {
		if(!num[there]) {
			dfs(there);
			low[curr] = min(low[curr], low[there]);
		} else if(vst[there]) {
			low[curr] = min(low[curr], num[there]);
		}
	}
	if(low[curr] == num[curr]) {
		vector<int> scc;
		while(!s.empty()) {
			int t = s.top();
			s.pop();
			scc.pb(t);
			vst[t] = false;
			if(t == curr) {
				break;
			}
		}
		sort(scc.begin(), scc.end());
		ans.pb(scc);
	}
}
void input() {
	cin >> v >> e;
	int a, b;
	for(int i=0; i<e; i++) {
		cin >> a >> b;
		adj[a].pb(b);
	}
}
void solve() {
	for(int i=1; i<=v; i++) {
		if(!num[i])	dfs(i);
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for(int i=0; i<(int)ans.size(); i++) {
		for(auto elem: ans[i]) {
			cout << elem << " ";
		}
		cout << "-1" << endl;
	}
}
int main(void) {
	FastIO;
	input();
	solve();
	return 0;
}
