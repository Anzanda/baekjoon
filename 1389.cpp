#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;
vector<int> adj[MAXN+1];
vector<int> ans;
int dijkstra(int x){
    vector<int> dp(n+1, INT_MAX);
    dp[x] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, x});

    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(cost > dp[here]) continue;
        for(auto there: adj[here]){
            int nextCost = 1 + cost;
            if(nextCost < dp[there]){
                dp[there] = nextCost;
                pq.push({-nextCost, there});
            }
        }
    }
    return accumulate(dp.begin()+1, dp.end(), 0);
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans.resize(n+1, 0);
    int min = INT_MAX;
    int midx = -1;
    for(int i=1; i<=n; i++){
        ans[i] = dijkstra(i);
        if(ans[i] < min){
            min = ans[i];
            midx = i;
        }
    }
    cout << midx;
    return 0;
}