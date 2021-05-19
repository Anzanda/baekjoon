#include <bits/stdc++.h>
using namespace std;
#define MAXN 800
int n, e;
vector<pair<int, int>> adj[MAXN+1];
vector<int> dijkstra(int x){
    vector<int> dp;
    dp.resize(n+1, INT_MAX);
    dp[x] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        if(cost > dp[here]) continue;

        for(auto there: adj[here]){
            int nextIdx = there.first;
            int nextCost = there.second + cost;
            if(dp[nextIdx] > nextCost){
                dp[nextIdx] = nextCost;
                pq.push({-nextCost, nextIdx});
            }
        }
    }

    return dp;
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int src, dst;
    int ans=0;
    int ans2=0;
    cin >> src >> dst;

    vector<int> dp = dijkstra(1);
    if(dp[src] == INT_MAX){
        cout << -1;
        return 0;
    }
    ans += dp[src];
    ans2 += dp[dst];

    dp = dijkstra(src);
    if(dp[dst] == INT_MAX || dp[n] == INT_MAX){
        cout << -1;
        return 0;
    }
    ans += dp[dst];
    ans2 += dp[n];

    dp = dijkstra(dst);
    if(dp[n] == INT_MAX || dp[src] == INT_MAX){
        cout << -1;
        return 0;
    }
    ans += dp[n];
    ans2 += dp[src];

    if(ans < ans2){
        cout << ans;
    }
    else    cout << ans2;

    return 0;
}