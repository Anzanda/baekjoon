#include <bits/stdc++.h>
using namespace std;
#define MAXN 8
int n,m;
int* arr;
void foo(int x, int cnt){
    if(cnt == m-1){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    arr[cnt] = x;
    for(int i=x+1; i<=n; i++){
        foo(i, cnt+1);
        arr[cnt] = x;
    }
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    arr = (int*)calloc(sizeof(int), m);
    for(int i=1; i<=n; i++){
        foo(i,0);
    }
}