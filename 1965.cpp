#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 1024
#define endl "\n"

int n;
int arr[MAX];
int dp[MAX];
int rundp(int now) {
    if(now == n-1) {
        dp[now] = 1;
        return 1;
    }
    if(dp[now] != -1) {
        return dp[now];
    }
    int ret = 0;
    for(int i=now+1; i<n; i++) {
        if(arr[now] < arr[i])
            ret = max(ret, rundp(i));
    }
    dp[now] = ret + 1;
    return dp[now];
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    for(int i=0; i<n; i++) {
        rundp(i);
    }
    cout << *max_element(dp, dp+n) << endl;
    return 0;
}