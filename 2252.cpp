#include <bits/stdc++.h>
#define MAXN 32000
#define fastIO iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> v[MAXN+1];
bool visited[MAXN+1];
void dfs(int now) {
    visited[now] = true;
    for(auto there: v[now]) {
        if(!visited[there])
            dfs(there);
    }
    cout << now << " ";
}
int main(void) {
    fastIO;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) 
            dfs(i);
    }
    return 0;
}