#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define MAXN 10000010

int n;
int arr[MAXN];
vector<int> lis;
int trace[MAXN];
int bs(int l, int r, int x) {
    int mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(lis[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
int main(void) {
    FastIO;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    lis.push_back(arr[0]);
    trace[0] = 0;
    for(int i=1; i<n; i++) {
        if(lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            trace[i] = lis.size()-1;
        } else {
            int idx = bs(0, lis.size()-1, arr[i]);
            lis[idx] = arr[i]; 
            trace[i] = idx;
        }
    }
    int sz = lis.size();
    cout << sz-- << endl;
    stack<int> s;
    for(int i=n-1; i>=0; i--) {
        if(sz == trace[i]) {
            sz--;
            s.push(arr[i]);
        }
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}