#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int T,n,m;
int a[MAXN];
int b[MAXN];
map<long long, long long> sumA;
int main(void){
    cin >> T;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    for(int i=0; i<n; i++){
        int tmp = 0;
        for(int j=i; j<n; j++){
            tmp+=a[j];
            sumA[tmp]++;
        }
    }
    
    long long ans = 0;
    for(int i=0; i<m; i++){
        int tmp = 0;
        for(int j=i; j<m; j++){
            tmp += b[j];
            ans += sumA[T-tmp];
        }
    }
    cout << ans << "\n";
    return 0;
}