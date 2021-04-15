#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<char> milk;
vector<int> adj[100001];
vector<bool> visited;
int root[100001];
void init(){
    for(int i=1; i<=n; i++){
        root[i] = i;
    }
}
void dfs(int x){
    visited[x] = true;
    for(auto t:adj[x]){
        if(visited[t])  continue;
        if(milk[t] == milk[x]){
            root[t] = x;
            dfs(t);
        }
    }
}
int Find(int x){
    if(x == root[x]){
        return x;
    }
    return root[x] = Find(root[x]);
}
int main(void){ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    string s; cin >> s;

    milk.resize(n+1);
    for(int i=1; i<=n; i++){
        milk[i] = s[i-1];    
    }
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init();
    visited.resize(n+1);
    for(int i=1; i<=n; i++){
        if(root[i] == i){
            dfs(i);
        }
    }
    for(int i=0; i<m; i++){
        int a, b; char c; 
        cin >> a >> b >> c;
        if(Find(a) != Find(b)){//노선이 다른 경우.
            cout << 1;
        }
        else if(milk[a] == c){//노선이 같은데 성공한 경우.
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    cout << "\n";
    return 0;
}