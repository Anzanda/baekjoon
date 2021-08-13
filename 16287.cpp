#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 400007
#define endl "\n"

int w, n;
int arr[5000];
bool dp[MAX];
int main(void) {
    FastIO;
    cin >> w >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int tmp = w - (arr[i] + arr[j]);
            if(tmp > 400000 || tmp <= 1) continue;
            if(dp[tmp]) {
                cout << "YES" << endl;
                return 0;
            }
        }
        for(int j=0; j<i; j++) {
            dp[arr[i]+arr[j]] = true; 
        }
    }
    cout << "NO" << endl;
    return 0;
}