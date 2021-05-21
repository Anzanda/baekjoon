#include <bits/stdc++.h>
using namespace std;

int n,m;

void foo(int* arr, int x, int cnt){
    arr[cnt] = x;
    if(cnt == m-1){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        free(arr);
        return;
    }
    for(int i=x; i<=n; i++){
        int* tmp = (int*)malloc(sizeof(int) * m);
        memcpy(tmp, arr, sizeof(int)*m);
        foo(tmp, i, cnt+1);
    }
    free(arr);
}
int main(void){iostream::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int* arr = (int*)calloc(sizeof(int), n);
        foo(arr, i,0);
    }
}