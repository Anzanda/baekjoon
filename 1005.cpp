#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int t, n, k, target;
int cost[MAXN+1];
int dp[MAXN+1];
void dfs(vector<vector<int>> adj, int x){
    int here = x;
    if(dp[here] >= 0)   return;
    int max = 0;
    for(auto there: adj[x]){
        if(dp[there] == -1){
            dfs(adj, there);
        }
        max = max > dp[there] ? max : dp[there];
    }
    dp[here] = max + cost[here];
}
int main(void){iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(cost, 0, sizeof cost);
        for(int i=1; i<=n; i++){
            cin >> cost[i];
        }
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=0; i<k; i++){
            int src, dst;
            cin >> src >> dst;
            adj[dst].push_back(src);
        }//어디서 시작할 지 정해야함.
        
        cin >> target;
        memset(dp, -1, sizeof dp);
        dfs(adj, target);

        cout << dp[target] << "\n";
    }
    return 0;
}
