#include <bits/stdc++.h>
#define MAXN 3*100000
using namespace std;

int n;
int arr[MAXN];
map<int, int> m;
int total;

int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        total++;
        m[arr[i]] += 1;
    }

    long long ans = 0;
    for(int i=0; i<n-1; i++){
        ans += total - m[arr[i]];
        m[arr[i]]--;
        total--;
    }
    cout << ans << "\n";

    return 0;
}