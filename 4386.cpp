#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 100
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define Precision cout << fixed, cout.precision(2)

int n;
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> edge;
int parent[MAXN];
int Find(int x) {
    if(x == parent[x])  return x;
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x != y)  parent[x] = y;
}
bool isUnion(int x, int y) {
    x = Find(x);
    y = Find(y);
    return x == y;
}
int main(void) {
    FastIO;
    Precision;
    cin >> n;
    star.resize(n);
    for(int i=0; i<n; i++) {
        cin >> star[i].first >> star[i].second;
    }
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
    double ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            double dist = sqrt(pow(star[i].first-star[j].first, 2)+pow(star[i].second-star[j].second,2));
            edge.push_back({dist, {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    for(auto el: edge) {
        if(!isUnion(el.second.first, el.second.second)) {
            Union(el.second.first, el.second.second);
            ans += el.first;
        }
    }
    cout << ans << endl;
    return 0;
}