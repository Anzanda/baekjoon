#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAXN 2000

int n,m;
int arr[MAXN];
int dp[MAXN][MAXN];
bool isRange(int l, int r) {
    if(l < 0 || l > n-1 || r <0 || r > n-1) {
        return false;
    }
    if(l > r) {
        return false;
    }
    return true;
}
bool isPalindrome(int l, int r) {
    if(!isRange(l,r)) {
        return false;
    }
    if(abs(l-r) <= 1) {
        if(arr[l] == arr[r]) {
            return true;
        } else {
            return false;
        }
    }
    //abs(l-r)이 2이상임!
    if(dp[l+1][r-1] == true) {
        if(arr[l] == arr[r]) {
            return true;
        }
    } 
    return false;
}
int main(void) {
    FastIO;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        int di = 0;
        while(isPalindrome(i-di, i+di)) {
            dp[i-di][i+di] = true;
            di++;
        }
    }
    for(int i=0; i<n; i++) {
        int di = 0;
        while(isPalindrome(i-di, (i+1)+di)) {
            dp[i-di][i+1+di] = true;
            di++;
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[a-1][b-1] << endl;
    }
    return 0;
}