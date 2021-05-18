#include <bits/stdc++.h>
#define MAXN 20000
using namespace std;

int n, m;
vector<int> adj[MAXN+1];
int dp[MAXN+1];
void dijkstra(int n){
    priority_queue<pair<int, int>> pq;
    pq.push({0, n});
    dp[n] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dp[here] < cost){
            continue;
        }
        for(auto t: adj[here]){
            int there = t;
            int nextCost = cost + 1;
            if(nextCost < dp[there]){
                dp[there] = nextCost;
                pq.push({-nextCost, there});
            }
        }
    }
}
int main(void){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) dp[i] = INT_MAX;
    dijkstra(1);
    int max = dp[1];
    bool flag = false;
    int cnt = 1;
    int midx = 1;
    for(int i=1; i<=n; i++){
        if(dp[i] == max){
            cnt++;
        }
        if(dp[i] > max){
            max = dp[i];
            cnt = 1;
            midx = i;
        }
    }
    cout << midx << " " << dp[midx] << " " << cnt << "\n";
    return 0;

}