#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl "\n"

int t;
int main(void) {
    FastIO;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 1;
        for(int i=0; i<b; i++) {
            ans = (ans * a)%10;
        }
        if(ans == 0)    ans = 10;
        cout << ans << endl;
    }
    return 0;
}