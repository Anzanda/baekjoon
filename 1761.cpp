#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 40404
#define LOG 20
#define pb push_back
#define ff first
#define ss second

typedef pair<int,int> pii;

int n, m;
vector<pii> adj[MAX];
int depth[MAX];
pii dp[MAX][LOG];
void depthDFS(int curr) {
    for(pii there: adj[curr]) {
        // cout << "there: " << there.ff << ", " << there.ss << endl;
        if(depth[there.ff] != -1)   continue;
        dp[there.ff][0] = {curr, there.ss};
        depth[there.ff] = depth[curr] + 1;
        depthDFS(there.ff);
    }
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    memset(dp, -1, sizeof dp);
    memset(depth, -1, sizeof depth);
    depth[1] = 0;
    depthDFS(1);
    for(int j=0; j<LOG-1; j++) {
        for(int i=2; i<=n; i++) {
            if(dp[i][j].ff != -1) {
                dp[i][j+1] = {dp[dp[i][j].ff][j].ff, dp[i][j].ss + dp[dp[i][j].ff][j].ss}; 
            }
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];
        int ans = 0;
        for(int j=0; diff; j++) {
            if(diff%2) {
                ans += dp[u][j].ss;
                u = dp[u][j].ff;
            }
            diff/=2;
        }
        if(u != v) {
            for(int j=LOG-1; j>=0; j--) {
                if(dp[u][j].ff!=-1 && dp[u][j].ff!=dp[v][j].ff) {
                    ans += dp[u][j].ss + dp[v][j].ss;
                    u = dp[u][j].ff;
                    v = dp[v][j].ff;
                }
            }
            ans += dp[u][0].ss;
            ans += dp[v][0].ss;
        }
        cout << ans << endl;
    }
    return 0;
}