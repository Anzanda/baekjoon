#include <bits/stdc++.h>
using namespace std;

int n, m;
void foo(int* arr, int x, int cnt){
    
    arr[cnt]=x;
    
    if(cnt == m-1){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        free(arr);
        return;
    }
    for(int i=x+1; i<=n; i++){
        int* v = (int*)malloc(sizeof(int)*m);
        memcpy(v, arr, sizeof(int)*m);  
        foo(v, i, cnt+1);
    }
    free(arr);
}
int main(void){ios_base::sync_with_stdio(false);cin.tie(nullptr);
    cin >> n >> m;
    int* arr;
    for(int i=1; i<=n; i++){
        arr = (int*)malloc(sizeof(int)*m);
        foo(arr, i, 0);
    }
    
    return 0;
}