#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)
#define MAXN 1000


int n, m;
vector<int> v[MAXN+1];
vector<int> ans;
bool vst[MAXN+1];
bool finished[MAXN+1];
bool flag;
void dfs(int now) {
    if(flag)    return;
    vst[now] = true;
    for(auto there: v[now]) {
        if(!vst[there]) {
            dfs(there);
        } else if(!finished[there]) {
            flag=true;
            return;
        }
    }
    finished[now] = true;
    ans.push_back(now);
}
int main(void) {
    FastIO;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int t;
        cin >> t;
        int num;
        int beforeNum = -1;
        while(t--) {
            cin >> num;
            if(beforeNum == -1) {
                beforeNum = num;
            } else {
                v[num].push_back(beforeNum);
                beforeNum = num;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(!vst[i])
            dfs(i);
    }
    if(flag) {
        cout << 0 << endl;
    } else {
        for(auto elem: ans) {
            cout << elem << endl;
        }
    }
    return 0;
}