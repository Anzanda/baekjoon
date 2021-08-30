#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define pb push_back
#define ff first
#define ss second

using pii = pair<int, int>;

const int MAX = 10000;

int n, m;
vector<pii> v[MAX+5];
int dp[MAX+5];
int s, e;
int roadCount;
void input() {
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].pb({b, w});
    }
    cin >> s >> e;
}
int rundp(int curr) {
    int& ret = dp[curr];
    if(ret != -1) {
        return ret;
    }
    if(curr == e) {
        return ret=0;
    }
    for(auto next: v[curr]) {
        ret = max(ret, rundp(next.ff)+next.ss);
    } 
    return ret;
}
bool vst[MAX+5];
void traceBack(int curr) {
    if(vst[curr])   return;
    if(dp[curr] == 0)   {
        return;
    }
    vst[curr] = true;
    for(auto next: v[curr]) {
        if(dp[curr] == dp[next.ff]+next.ss) {
            roadCount++;
            traceBack(next.ff);
        }
    }
}
void solve() {
    memset(dp, -1 ,sizeof dp);
    cout << rundp(s) << endl;
    traceBack(s);
    cout << roadCount << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}