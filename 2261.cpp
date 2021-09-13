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
vector<pii> sortedPos[MAX];
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> pos[i].ff >> pos[i].ss;
    }
}
int getDist(pii a, pii b) {
    return (a.ff-b.ff)*(a.ff-b.ff) + (a.ss-b.ss)*(a.ss-b.ss);
}
struct cmp {
    bool operator()(pii p1, pii p2) const {
        if(p1.ss == p2.ss)  return p1.ff < p2.ff;
        return p1.ss < p2.ss;
    }
};
void solve() {
    sort(pos, pos+n);
    int ans = getDist(pos[0], pos[1]);
    int startIdx = 0;
    set<pii, cmp> cand = {pos[0], pos[1]};
    for(int i=2; i<n; i++) {
        int idx = startIdx;
        while(idx < i) {
            int dist = pos[i].ff - pos[idx].ff;
            if(dist*dist > ans) {
                cand.erase(pos[idx]);
                idx++; 
            } else {
                break;
            }
        } 
        startIdx = idx;
        int d = (int)sqrt((double)ans)+1;
        pii lowerVal = {-10000, pos[i].ss-d};
        pii upperVal = {10000, pos[i].ss+d};
        auto lowerIt = cand.lower_bound(lowerVal);
        auto upperIt = cand.upper_bound(upperVal);
        for(auto it=lowerIt; it!=upperIt; it++ ){
            int dist = getDist(pos[i], *it);
            ans = min(ans, dist);
        }
        cand.insert(pos[i]);
    }    
    cout << ans << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}