#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define INF 987654321

using pii = pair<int , int>;

const int MAX = 100000+7;

int n;
pii pos[MAX];
pii reversePos[MAX];
vector<pii> sortedPos[MAX];
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> pos[i].ff >> pos[i].ss;
        reversePos[i] = {pos[i].ss, pos[i].ff};
    }
}
int getDist(pii a, pii b) {
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}
int lowerBound(vector<pii> &v, int x) {     
    int lf = 0;
    int rg = v.size();
    while(lf < rg) {
        int mid = (lf + rg) / 2;
        if(v[mid].ss < x) {
            lf = mid+1;
        } else {
            rg = mid;
        }
    }
    return rg;
}
int ans = INF;
void solve(pii pos[MAX]) {
    sort(pos, pos+n);
    int beforeValue = pos[0].ff;
    int idx = 0;
    sortedPos[0] = vector<pii>();
    for(int i=0; i<n; i++) {
        if(beforeValue == pos[i].ff) {
            sortedPos[idx].pb(pos[i]);
        } else {
            sortedPos[++idx] = vector<pii>();
            sortedPos[idx].pb(pos[i]);
            beforeValue = pos[i].ff;
        }
    } 
    for(int i=1; i<sortedPos[0].size(); i++) {
        ans = min(ans, getDist(sortedPos[0][i], sortedPos[0][i-1]));
    }
    for(int i=1; i<MAX; i++) {
        if(sortedPos[i].empty())  {
            break;
        }  
        for(int j=0; j<sortedPos[i].size(); j++) {
            int idx = lowerBound(sortedPos[i-1], sortedPos[i][j].ss);
            if(idx < sortedPos[i-1].size())
                ans = min(ans, getDist(sortedPos[i][j], sortedPos[i-1][idx]));
            if(idx > 0 && idx-1 < sortedPos[i-1].size())
                ans = min(ans, getDist(sortedPos[i][j], sortedPos[i-1][idx-1]));
            if(j == 0)  continue;
            ans = min(ans, getDist(sortedPos[i][j], sortedPos[i][j-1]));
        }
    }
}
int main(void) {
    FastIO;
    input();
    solve(pos);
    solve(reversePos);
    cout << ans << endl;
    return 0;
}