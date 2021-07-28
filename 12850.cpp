#include <bits/stdc++.h>
using namespace std;

#define pb push_back
int D;
int dp[(1<<14)];
bool vst[(1<<14)];
bool node[8];
vector<int> g[8];
void init() {
    g[0].pb(1), g[0].pb(2);
    g[1].pb(0), g[1].pb(2), g[1].pb(3);
    g[2].pb(0), g[2].pb(1), g[2].pb(3), g[2].pb(4);
    g[3].pb(1), g[3].pb(2), g[3].pb(4), g[3].pb(5);
    g[4].pb(2), g[4].pb(3), g[4].pb(5), g[4].pb(6);
    g[5].pb(3), g[5].pb(4), g[5].pb(7);
    g[6].pb(4), g[6].pb(7);
    g[7].pb(5), g[7].pb(6);
}
void printBit(int mask) {
    cout << "mask: " << mask << endl;
    for(int i=0; i<14; i++) {
        if(mask&(1<<i)) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}
void dfs(int now, int edge, int mask) {
    printBit(mask);
    vst[mask] = true;
    for(auto there: g[now]) {
        int nextEdge= now + there;
        cout << "nextEdge: " << nextEdge << endl;
        if(!(mask&(1<<nextEdge))) {
            dfs(there, nextEdge, mask|(1<<nextEdge));        
        }
    }
}
int main(void) {
    cin >> D;
    init();
    dfs(0, 0, 0);
    int ans = 0;
    cout << endl;
    for(int i=0; i<(1<<14); i++) {
        if(vst[i] == true) {
            int cnt = 0;
            for(int j=0; j<14; j++) {
                if((i&(1<<j))) {
                    cnt++;
                }
            }            
            if(D > cnt*2) {
                int tmp = D - cnt * 2;
                if(tmp%2 == 0) {

                } else {
                    continue;
                }
            } 
        }
    }
}