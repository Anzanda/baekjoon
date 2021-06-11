#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int v, e;
vector<pair<int, pair<int, int>>> g;
int Parent[MAXN+1];
int Find(int x){
    if(Parent[x] == x)  return x;
    else    return Parent[x] = Find(Parent[x]);
}
void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    
    if(x != y)  Parent[x] = y;
}
bool SameParent(int x, int y){
    x = Find(x);
    y = Find(y);
    
    if(x == y)  return true;
    else        return false;
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b ,w;
        cin >> a >> b >> w;
        g.push_back({w, {a, b}});
    }
    sort(g.begin(), g.end());

    for(int i=1; i<=v; i++){
        Parent[i] = i;
    }

    int ans = 0;
    for(int i=0; i<e; i++){
        if(!SameParent(g[i].second.first, g[i].second.second)){
            ans += g[i].first;
            Union(g[i].second.first, g[i].second.second);
        }
    }
    cout << ans << "\n";
    return 0;
}
