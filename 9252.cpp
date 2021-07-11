#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)
#define endl "\n"
#define MAXN 1000

string s1;
string s2;
int dp[MAXN+1][MAXN+1];
int main(void) {
    FastIO;
    cin >> s1 >> s2;
    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s1[i-1] == s2[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    int ans = 0;
    int i = s1.length();
    int j = s2.length();
    ans = dp[i][j];
    stack<char> s;
    while(dp[i][j] != 0) {
        if(dp[i-1][j] == dp[i][j]) {
            i--;
        } else if(dp[i][j-1] == dp[i][j]) {
            j--;
        } else if(dp[i][j] - 1 == dp[i-1][j-1]) {
            s.push(s1[i-1]);
            i--;
            j--;
        }
    }
    cout << ans << endl;
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}