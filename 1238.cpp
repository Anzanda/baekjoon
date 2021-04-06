#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int n, m, x;
vector<pair<int ,int>> g[1001];
vector<int> bfs(int node){
    vector<int> dp(n+1, 1000000000);
    dp[node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, node});
    while(pq.size()){
        int hereCost = pq.top().first;
        int hereCur = pq.top().second;
        pq.pop();

        if(dp[hereCur] < hereCost){
            continue;
        }
        for(auto there: g[hereCur]){
            int thereDist = there.first;
            int thereCur = there.second;

            int thereCost = thereDist + hereCost; 
            if(dp[thereCur] > thereCost){
                dp[thereCur] = thereCost;
                pq.push({thereCost, thereCur});
            }
        }
    }
    return dp;
}
int main(void){
    cin >> n >> m >> x;

    int start, end, time;
    for(int i=0; i<m; i++){
        cin >> start >> end >> time;
        g[start].push_back({time, end});
    }

    vector<int> fromX = bfs(x);

    int ans = -1;
    for(int i=1; i<=n; i++){
        vector<int> toX = bfs(i);
        
        if(toX[x] + fromX[i] >= 100000000){
            continue;
        }

        ans = max(ans, toX[x] + fromX[i]);
    }
    cout << ans;
    return 0;
}