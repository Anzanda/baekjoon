#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100007
#define pb push_back

const int LOG_MAX = (int)log2(MAX)+2;

int n, m;
vector<int> adj[MAX];
int parent[MAX][18];
int depth[MAX];
void initDepth(int curr) {
    for(int there: adj[curr]) {
        if(depth[there] == -1) {
            parent[there][0] = curr;
            depth[there] = depth[curr] + 1;
            initDepth(there);
        }
    }
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n-1; i++) {
       int u, v;
       cin >> u >> v;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    memset(parent, -1, sizeof parent);
    memset(depth, -1, sizeof depth);
    depth[1] = 0;
    initDepth(1); //depth랑 parent[i][0] 초기화.
    for(int j=0; j<LOG_MAX-1; j++) {//2^0부터 2^LOG_MAX까지 차례로 초기화.
        for(int i=2; i<=n; i++) {
            if(parent[i][j] != -1)
                parent[i][j+1] = parent[parent[i][j]][j];
        }
    }
    //parent배열이 완성됨.
    cin >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        if(depth[u] < depth[v]) swap(u,v); //무조건 u가 크거나 같은경우만 생각.
        int diff = depth[u] - depth[v];
        for(int j=0; diff; j++) { //diff가 같아질 때까지 u를 업데이트.
            if(diff%2) u = parent[u][j]; //2진수 연산으로 생각해야하는 부분이다.
            diff /= 2;//11 = 1011(2)인데, 이는 8+2+1이므로 4인 경우를 업데이트 해주면 안된다.
            //mod의 결과가 1인 경우 == 2진수가 1인경우.
        }
        if(u != v) {
            for(int j=LOG_MAX-1; j>=0; j--) {
                if(parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        cout << u << endl;
    }
    return 0;
}
