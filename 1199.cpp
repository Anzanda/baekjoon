#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int n;
int adj[MAXN+1][MAXN+1];
int degree[MAXN+1];
vector<int> ans;
void dfs(int x){
    for(int i=1; i<=n; i++){
        while(adj[x][i]){
            adj[x][i]--;
            adj[i][x]--;
            dfs(i);
        }
    }
    ans.push_back(x);
}
int main(void){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> adj[i][j];
            degree[i] += adj[i][j];
            degree[j] += adj[i][j];           
        }
    }
    for(int i=1; i<=n; i++){
        degree[i] /= 2;
        if(degree[i] % 2){
            cout << -1 << "\n";
            return 0;
        }
    }
    dfs(1);
    for(auto it = ans.rbegin(); it!=ans.rend(); it++){
        cout << *it << " ";
    }
    return 0;
}