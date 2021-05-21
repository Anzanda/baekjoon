#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int t, n, k;
int cost[MAXN+1];
int dp[MAXN+1];
void dfs(int x){

}
int main(void){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> cost[i];
        }
        vector<vector<int>> adj(n+1, vector<int>());
        for(int i=0; i<k; i++){
            int src, dst;
            cin >> src >> dst;
            adj[dst].push_back(src);
        }//어디서 시작할 지 정해야함.


    }
}