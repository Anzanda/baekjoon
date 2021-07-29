#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define FastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MOD 1000000007LL

vector<vector<ll>> v = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};
vector<vector<ll>> mul(vector<vector<ll>>& m1, vector<vector<ll>>& m2) {
    vector<vector<ll>> ret(8, vector<ll>(8));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            ll tmp = 0;
            for(int k=0; k<8; k++) {
                tmp = (tmp + (m1[i][k] * m2[k][j]))%MOD;
            }
            ret[i][j] = tmp%MOD;
        }    
    }
    return ret;
}
ll D;
int main(void) {
    cin >> D;
    vector<vector<ll>> ans(8, vector<ll>(8));
    for(int i=0; i<8; i++){ 
        ans[i][i] = 1;
    }
    vector<vector<ll>> factor = v;
    while(D) {
        if(D & 1) {
            ans = mul(ans, factor);
            D -= 1;
        }
        factor = mul(factor, factor);
        D /= 2;
    }
    cout << ans[0][0] << endl;
    return 0;
}