#include <bits/stdc++.h>
#define FastIO iostream::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define endl "\n"
#define MAXN 100000
#define INF 987654321
using namespace std;

int n;
int arr[MAXN];
int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int lidx = 0;
    int ridx = n-1;
    int min = INT_MAX;
    pair<int, int> ans;
    while(lidx < ridx) {
        int tmp = arr[ridx]+arr[lidx];
        if(tmp > 0) {
            if(min >= abs(tmp)) {
                min = abs(tmp);
                ans = {arr[lidx], arr[ridx]};
            }
            ridx--;
        } else if(tmp < 0) {
            if(min >= abs(tmp)) {
                min = abs(tmp);
                ans = {arr[lidx], arr[ridx]};
            }
            lidx++;
        } else {
            ans = {arr[lidx], arr[ridx]};
            break;
        }
    }
    cout <<  ans.first << " " << ans.second << endl;
    return 0;
}