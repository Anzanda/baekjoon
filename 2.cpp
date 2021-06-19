#include <bits/stdc++.h>
using namespace std;

int n;
int main(void){
    cin >> n;
    
    int i;
    int sum = 0;
    for(i=0; sum<n; i++){
        sum += i;
    }
    
    cout << i-1 << "\n";
    return 0;
}