#include <bits/stdc++.h>
#define x first
#define y second
#define MAXN 3000
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
using namespace std;

int n;
int parent[MAXN];
vector<pair<pair<int,int>,pair<int,int>>> v;
void Print(int x1, int y1, int x2, int y2){
    printf("(%d, %d) (%d, %d)\n", x1, y1, x2, y2);
}
int judge(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    pair<int, int> grad = {p2.x-p1.x, p2.y-p1.y};
    int t = grad.second*(p3.x-p1.x)-grad.first*(p3.y-p1.y);
    if(t > 0)   return 1;
    else if(t == 0) return 0;
    else    return -1;
}
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
bool isRange(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int t1 = p1.x-p3.x;
    int t2 = p2.x-p3.x;
    return t1*t2<=0;
}
bool isGroup(int i, int j) {
    int p1 = judge(v[j].first, v[j].second, v[i].first);
    int p2 = judge(v[j].first, v[j].second, v[i].second);
    int p3 = judge(v[i].first, v[i].second, v[j].first);
    int p4 = judge(v[i].first, v[i].second, v[j].second);
    
    if(p1*p2 ==0 && p3*p4 == 0){
        if(v[i].first > v[i].second)    swap(v[i].first, v[i].second);
        if(v[j].first > v[j].second)    swap(v[j].first, v[j].second);
        return v[i].second >= v[j].first && v[j].second >= v[i].first;
    }

    return p1*p2<=0 && p3*p4<=0;
}
int main(void){
    fastIO;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin >> v[i].first.x >> v[i].first.y >> v[i].second.x >> v[i].second.y;
    }
    
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(isGroup(i,j)){
                Union(i, j);
            }
        }
    }
    
    map<int, int> m;
    for(int i=0; i<n; i++){
        m[Find(i)]++;
    }

    int groupCount = 0;
    int groupMax = 0;
    for(auto iter=m.begin(); iter!=m.end(); iter++){
        if(iter->second > groupMax){
            groupMax = iter->second;
        }
        groupCount++;
    }
    cout << groupCount << endl;
    cout << groupMax << endl;

    return 0;
}