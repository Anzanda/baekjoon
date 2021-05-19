#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
int n, m;
vector<pair<int,int>> adj[MAXN+1];
vector<int> dijkstra(int x){
    vector<int> dp;
    dp.resize(n+1, INT_MAX);
    dp[x] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0,x});

    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost > dp[here]) continue;

        for(auto there: adj[here]){
            int nextCost = cost + there.second;
            int nextIdx = there.first;
            if(dp[nextIdx] > nextCost){
                dp[nextIdx] = nextCost;
                pq.push({-nextCost, nextIdx});
            }
        }
    }

    return dp;
}
int main(void){iostream::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    int src, dst;
    cin >> src >> dst;

    vector<int> dp = dijkstra(src);
    cout << dp[dst];

    return 0;
}