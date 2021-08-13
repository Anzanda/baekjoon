#include <bits/stdc++.h>
using namespace std;

#define MAX 100007
#define endl "\n"
#define FastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 987654321
#define f first
#define s second

int n;
int main(void) {
    FastIO;
    cin >> n;
    int arr[3], minDp[2][3], maxDp[2][3];
    cin >> arr[0] >> arr[1] >> arr[2];
    for(int i=0; i<3; i++) {
        maxDp[0][i] = maxDp[1][i] = arr[i];
        minDp[0][i] = minDp[1][i] = arr[i];
    }
    for(int i=1; i<n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        maxDp[1][0] = max(maxDp[0][0], maxDp[0][1]) + arr[0];
        maxDp[1][1] = max({maxDp[0][0], maxDp[0][1], maxDp[0][2]}) + arr[1];
        maxDp[1][2] = max(maxDp[0][1], maxDp[0][2]) + arr[2];
        minDp[1][0] = min(minDp[0][0], minDp[0][1]) + arr[0];
        minDp[1][1] = min({minDp[0][0], minDp[0][1], minDp[0][2]}) + arr[1];
        minDp[1][2] = min(minDp[0][1], minDp[0][2]) + arr[2];
        
        memcpy(maxDp[0], maxDp[1], sizeof(int)*3);
        memcpy(minDp[0], minDp[1], sizeof(int)*3);
    }
    pair<int ,int> ans;
    ans.f = max({maxDp[1][0], maxDp[1][1], maxDp[1][2]});
    ans.s = min({minDp[1][0], minDp[1][1], minDp[1][2]});
    cout << ans.f << " " << ans.s << endl;
    return 0;
}