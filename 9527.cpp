#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)

typedef long long int ll;

ll dp[100];
ll computeZero(int n) {
    if(n == 0) {
        return dp[n];
    }
    if(n == 1) {
        return dp[n] = 1;
    } else {
        return dp[n] = 2 * computeZero(n-1) + pow(2, n-1);
    }
}
int main(void) {
    FastIO;
    ll l, r;
    cin >> l >> r;
    l -= 1;
    ll ans = 0;
    for(int i=63; i>=0; i--) {
        ll mask = (1LL << i);
        if(mask&r) {
            ans += computeZero(i) + (r - mask + 1);
            r -= mask;

        }
    }
    if(l != 0) {
        for(int i=63; i>=0; i--) {
            ll mask = (1LL << i);
            if(mask&l) {
                ans -= computeZero(i) + (l - mask + 1);
                l -= mask;
            }
        }
    }
    cout << ans << endl;
    return 0;
}