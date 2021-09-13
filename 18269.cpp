#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

int n;
string str;
void input() {
    cin >> n;
    cin >> str;
}
void solve() {
    int sz = 1;
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n-sz+1; j++) {
                bool isSame = true;
                for(int k=0; k<sz; k++) {
                    if(str[i+k] != str[j+k]) {
                        isSame = false;
                    }
                }
                if(isSame)  flag=true;
            }
        }
        sz++;
    }
    cout << sz-1 << endl;
}
int main() {
    FastIO;
    input();
    solve();
    return 0;
}