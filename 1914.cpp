#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

long long int n, k;
void solve(int now, int src, int dst) {
    if(now == 1) {
        cout << src << " " << dst << endl;
        return;
    }
    solve(now-1, src, 6-src-dst);
    cout << src << " " << dst << endl;
    solve(now-1, 6-src-dst, dst);
} 
int main(void) {
    FastIO;
    cin >> n;
    if(n > 20) {
        string ans = to_string(pow(2, n));
        int idx = ans.find('.');
        ans = ans.substr(0, idx);
        ans[ans.length()-1] -= 1;
        cout << ans << endl;
    } else {
        cout << (1<<n)-1 << endl;
        solve(n, 1, 3);
    }
    return 0;
}