#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define INF 987654321

using pii = pair<int,int>;

const int MAX = 1e5;
const int LOG = 18;

int n;
vector<pii> adj[MAX+1];
int depth[MAX+1];
pair<int, pii>dp[MAX+1][LOG];
int k;
void input() {
    cin >> n;
    int a, b, w;
    for(int i=0; i<n-1; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
}
void initDepth(int curr) {
     for(auto there: adj[curr]) {
         if(depth[there.ff] == -1) {
             depth[there.ff] = depth[curr]+1;
             dp[there.ff][0] = {curr, {there.ss, there.ss}};
             initDepth(there.ff);
         }
     }
}
void initSparseTable() {
    for(int j=1; j<LOG; j++) {
        for(int i=1; i<=n; i++) {
            if(dp[i][j-1].ff == 0)  continue;
            dp[i][j] = {dp[dp[i][j-1].ff][j-1].ff, {
                max(dp[dp[i][j-1].ff][j-1].ss.ff, dp[i][j-1].ss.ff),
                min(dp[dp[i][j-1].ff][j-1].ss.ss, dp[i][j-1].ss.ss)}};
        }
    }
}
void LCA(int u, int v) {
    int m=INF, M=-1;
    if(depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0; diff; i++) {
        if(diff&1) {
            M = max(M, dp[u][i].ss.ff);
            m = min(m, dp[u][i].ss.ss);
            u = dp[u][i].ff;
        }
        diff >>= 1;
    }
    if(u == v) {
        cout << m << " " << M << endl;
        return;
    }
    // if(u == v) return u;
    for(int i=LOG-1; i>=0; i--) {
        if(dp[u][i].ff != dp[v][i].ff) {
            M = max({M, dp[u][i].ss.ff, dp[v][i].ss.ff});
            m = min({m, dp[u][i].ss.ss, dp[v][i].ss.ss});
            u = dp[u][i].ff;
            v = dp[v][i].ff;
        }
    }
    M = max({M, dp[u][0].ss.ff, dp[v][0].ss.ff});
    m = min({m, dp[u][0].ss.ss, dp[v][0].ss.ss});
    cout << m << " " << M << endl;
}
void solve() {
    memset(depth, -1, sizeof depth);
    depth[0] = 0;
    initDepth(1);
    initSparseTable(); 
    cin >> k;
    int a, b;
    for(int i=0; i<k; i++) {
        cin >> a >> b;
        LCA(a, b);
    }
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}