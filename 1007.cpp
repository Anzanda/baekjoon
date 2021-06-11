#include <bits/stdc++.h>
using namespace std;

int t,n,totalX, totalY;
double m;
vector<pair<int, int>> v;
void dfs(int x, int cnt, int a, int b){
    //cout << "x: " << x << "cnt: " << cnt << endl;
    a += v[x].first;
    b += v[x].second;
    if(cnt == n/2){
        //cout << "a: " << a << "b: " << b << endl;
        double dist = sqrt(pow(totalX-a*2,2)+pow(totalY-b*2,2));
        m = m > dist ? dist : m;
        return;
    }
    for(int i=x+1; i<n; i++){
        dfs(i, cnt+1, a, b);
    }
}
void solve(){
    m=1.798e+307;
    dfs(0,1,0,0);
}
int main(void){iostream::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout << fixed;
    cout.precision(12);
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(n);
        totalX=0;
        totalY=0;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            v[i]={x,y};
            totalX += x;
            totalY += y;
        }
        solve();

        cout << m << "\n";
    }
    return 0;
}