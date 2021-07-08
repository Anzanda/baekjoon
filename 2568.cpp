#include <bits/stdc++.h>
using namespace std;

#define FastIO iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 500000
#define endl "\n"

int n;
vector<int> dp;
map<int, int> m;
int arr[MAXN+1];
int lisIndex(int start, int end, int target) {
    int l = start;
    int r = end;
    while(l < r) {
        int m = (l+r)/2;
        if(dp[m] >= target) {
            r = m;
        } else {
            l = m+1;
        }
    }
    return r;
}
int main(void) {
    FastIO;
    cin >> n;
    dp.resize(n);
    for(int i=0; i<n; i++) {
        int src, dst;
        cin >> src >> dst;
        arr[src] = dst;
        m[dst] = src;
    }
    int length = 0;
    stack<int> s;
    for(int i=1; i<=MAXN; i++) {
        if(arr[i] == 0) continue;
        if(dp[length] < arr[i]){
            dp[++length] = arr[i];
            s.push(arr[i]);
        }
        else {
            int newIdx = lisIndex(0,length,arr[i]);
            if(newIdx == length) {
                if(!s.empty())
                    s.pop();
                s.push(arr[i]);
            }
            dp[newIdx] = arr[i];
        }
    }
    cout << (n-length) << endl;

    while(!s.empty()) {
        m[s.top()]=0;
        s.pop();
    }
    vector<int> tmp;
    for(auto iter=m.begin(); iter!=m.end(); iter++) {
        if(iter->second != 0)
            tmp.push_back(iter->second);
    }
    sort(tmp.begin(), tmp.end());
    for(int i=0; i<tmp.size(); i++) {
        cout << tmp[i] << endl;
    }
    
    return 0;
}