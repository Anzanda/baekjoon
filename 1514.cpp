#include <bits/stdc++.h>
using namespace std;

#define MAX 128
#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987645321

int n;
int arr[MAX];
int t[MAX];
int dp[MAX][10][10];
int rundp(int now, int wa, int wb){
    if(now == n) {
        return 0;
    }
    int a = (arr[now] + wa + 10)%10;
    int b = (arr[now+1] + wb + 10)%10;
    int &ret = dp[now][a][b];
    if(ret != -1) {
        return ret;
    }
    ret = INF;
    int cnt = (t[now] - a + 10)%10;//양수 가중치 cnt, 음수 가중치 10-cnt
    for(int i=0; i<=1; i++) {
        int tmpCnt = i ? 10-cnt : cnt;
        for(int j=0; j<=tmpCnt; j++) {
            for(int k=0; k<=j; k++) {
                int val = (tmpCnt-j+2)/3 + (j-k+2)/3 + (k+2)/3;
                ret = min(ret, val+rundp(now+1, ((i?-j:j)+wb)%10, (i?-k:k)));
            }
        }
    }
  
    return ret;
}
int main(void) {
    FastIO;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        arr[i] = s[i]-'0';
    }
    cin >> s;
    for(int i=0; i<s.length(); i++) {
        t[i] = s[i]-'0';
    }
    memset(dp, -1, sizeof dp);
    cout << rundp(0, 0, 0) << endl;
    return 0;
}