#include <bits/stdc++.h>
using namespace std;

#define FastIO iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 5000
#define endl "\n"

typedef long long int ll;
typedef struct answer {
    ll a,b,c;
}Answer;

int n;
vector<ll> arr;
ll minTotal;
bool ansFlag;
Answer ans;
void twoPointer(int pivot, int start, int end) {
    int lidx = start;
    int ridx = end;
    while(lidx < ridx) {
        ll tmp = pivot + arr[lidx] + arr[ridx];
        if(tmp > 0) {
            if(minTotal > abs(tmp)) {
                minTotal = abs(tmp);
                ans = {pivot, arr[lidx], arr[ridx]};
            }
            ridx--;
        } else if(tmp < 0) {
            if(minTotal > abs(tmp)) {
                minTotal = abs(tmp);
                ans = {pivot, arr[lidx], arr[ridx]};
            }
            lidx++;
        } else {
            ans = {pivot, arr[lidx], arr[ridx]};
            ansFlag = true;
            break;
        }
    }
}
int main(void) {
    FastIO;
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    minTotal = (ll)INT_MAX*2;
    for(int i=0; !ansFlag && i < n-2; i++) {
        twoPointer(arr[i], i+1, n-1);
    }
    cout << ans.a << " " << ans.b << " " << ans.c << endl;
    return 0;
}