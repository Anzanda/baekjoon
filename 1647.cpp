#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, m;
vector<pair<int, pair<int, int>>> v;

int parent[MAXN+1];
int Find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        parent[x] = y;
    }
}
bool IsSameParent(int x, int y){
    x = Find(x);
    y = Find(y);
    return x == y;
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({w, {a,b}});
    }
    
    sort(v.begin(), v.end());
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    int count = 0;
    long long ans = 0;
    for(int i=0; count != n-2 && i<v.size(); i++){
        if(!IsSameParent(v[i].second.first, v[i].second.second)){
            ans += v[i].first;
            Union(v[i].second.first, v[i].second.second);
            count++;
        }
    }

    cout << ans << "\n";
    return 0;
}