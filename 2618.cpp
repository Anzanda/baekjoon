#include <bits/stdc++.h>
using namespace std;

#define MAX 1024
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987645321
#define f first
#define s second

int n, w;
pair<int,int> crime[MAX];
int dp[MAX][MAX];
int calculateDist(pair<int ,int> a, pair<int,int> b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}
int rundp(int x, int y) {
    if(x == w || y == w) {
        return 0;
    }
    if(dp[x][y] != -1) {
        return dp[x][y];
    }
    int next = max(x,y) + 1;
    int distA, distB;
    if(x == 0) {
        distA = calculateDist(crime[x], crime[next]);
    } else {
        distA = calculateDist(crime[x], crime[next]);
    }
    if(y == 0) {
        distB = 2 * (n-1) - calculateDist(crime[0], crime[next]);
    } else {
        distB = calculateDist(crime[y], crime[next]);
    }
    dp[x][y] = min(rundp(next, y)+distA, rundp(x, next)+distB);
    return dp[x][y];
}
void trace(int x, int y) {
    if(x == w || y == w) {
        return;
    }
    int next = max(x,y) + 1;
    int distA, distB;
    distA = calculateDist(crime[x], crime[next]);
    distB = calculateDist(crime[y], crime[next]);
    if(y == 0){
        distB = 2*(n-1) - distB;
    }
    if(distA+dp[next][y] < distB+dp[x][next]) {
        cout << "1" << endl;
        trace(next ,y);
    } else {
        cout << "2" << endl;
        trace(x, next);
    }
}
int main(void) {
    cin >> n;
    cin >> w; 
    crime[0] = {1, 1};
    for(int i=1; i<=w; i++) {
        cin >> crime[i].f >> crime[i].s; 
    }
    memset(dp, -1, sizeof dp);
    rundp(0, 0);
    cout << dp[0][0] << endl;
    trace(0, 0);
    return 0; 
}