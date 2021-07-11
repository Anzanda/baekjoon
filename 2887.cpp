#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 100000
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

int n;
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;
vector<pair<int, pair<int,int>>> edge;
int parent[MAXN+1];
int Find(int x) {
    if(x == parent[x]) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y) {
        parent[x] = y;
    }
}
bool isUnion(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x == y;
}
int main(void) {
    FastIO;
    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    for(int i=0; i<n; i++) {
        cin >> x[i].first >> y[i].first >> z[i].first;
        x[i].second = i;
        y[i].second = i;
        z[i].second = i;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for(int i=1; i<n; i++) {
        edge.push_back({(x[i].first-x[i-1].first), {x[i].second, x[i-1].second}});
        edge.push_back({(y[i].first-y[i-1].first), {y[i].second, y[i-1].second}});
        edge.push_back({(z[i].first-z[i-1].first), {z[i].second, z[i-1].second}});
    }
    sort(edge.begin(), edge.end());
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    long long ans = 0;
    for(auto el: edge) {
        
        if(!isUnion(el.second.first, el.second.second)) {
            Union(el.second.first, el.second.second);
            ans += el.first;
        }
    }   
    cout << ans << endl;
    return 0;
}