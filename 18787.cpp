#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

int n;
string A;
string B;
void input() {
    cin >> n;
    cin >> A;
    cin >> B;
}
void solve() {
    int ans = 0;
    bool eq = true;
    for(int i=0; i<n; i++) {
        if(A[i] == B[i]) {
            eq = true;
        } else {
            if(eq) {
                eq = false;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
int main(void) {
    FastIO;
    input();
    solve();
    return 0;
}