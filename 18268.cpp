#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 21;

int n, k;
int arr[MAX];
int order[MAX][MAX];
void input() {
    cin >> k >> n;
}
int ans;
void solve() {
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[j];
        }
        for(int j=0; j<n; j++) {
            int lf = arr[j];
            for(int l=j+1; l<n; l++) {
                int rg = arr[l];
                order[lf][rg]++; 
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(order[i][j] == k) {
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
