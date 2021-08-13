#include <bits/stdc++.h>
using namespace std;

#define MAX 2000+7
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
vector<int> arr;
int dp[MAX][MAX];
int lowerBound(int l, int r, int x) {
    int m;
    while(l < r) {
        m = (l + r) / 2;
        if(arr[m] < x) {
            l = m + 1; 
        } else {
            r = m;
        }
    }
    return r;
}
int main(void) {
    FastIO;
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int ans = -1;
    dp[0][0] = 1;
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
            if(j==0) {
                dp[i][j] = 2;
                ans = max(dp[i][j], ans);
                continue;
            }
            int idx = lowerBound(0, j-1, arr[j]-(arr[i]-arr[j]));
            while(idx < j-1 && arr[idx] == arr[idx+1]) {
                idx++;
            }
            if((arr[j]-arr[idx]) == (arr[i]-arr[j])) {
                dp[i][j] += dp[j][idx] + 1;
            } else {
                dp[i][j] = 2;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    if(ans == -1)   ans = 1;
    cout << ans << endl;
    return 0;
}