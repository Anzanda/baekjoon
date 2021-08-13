#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
void hanoi(int cnt, int src, int dst) {
    if(cnt == 1) {
        cout << src << " " << dst << endl;
        return;
    }
    hanoi(cnt-1, src, 6-src-dst);
    cout << src << " " << dst << endl;
    hanoi(cnt-1, 6-src-dst, dst); 
}
int main(void) {
    FastIO;
    cin >> n;
    cout << (1<<n)-1 << endl;
    hanoi(n, 1, 3);
    return 0;
}
