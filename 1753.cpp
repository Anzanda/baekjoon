#include <bits/stdc++.h>

#define INF 0x7fffffff
#define MAXN 300000

using namespace std;

int v, e;
int target;
vector<pair<int, int>> g[MAXN];

vector<int> dijkstra(int x){
    vector<int> dp(v+1, INT_MAX);
    dp[x] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({0,x});
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        if(dp[here] < cost){
            continue;
        }

        for(auto t: g[here]){
            int there = t.second;
            int nextDist = t.first + cost;
            if(dp[there] > nextDist){
                dp[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    return dp;
}
void printAll(){
    for(int i=1; i<=v; i++){
        printf("when i=%d\n", i);
        for(auto t: g[i]){
            printf("%d ", t.second);
        }
        printf("\n");
    }
}
int main(void){
    cin >> v >> e;
    cin >> target;
    for(int i=0; i<e; i++){
        int src, dst, w;
        cin >> src >> dst >> w;
        g[src].push_back({w, dst});
        g[dst].push_back({w, src});
    }

    vector<int> dp= dijkstra(target);
    for(int i=1; i<=v; i++){
        if(dp[i] == INT_MAX)    cout << "INF\n";
        else                    cout << dp[i] << "\n";
    }
    
    return 0;
}