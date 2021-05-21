#include <bits/stdc++.h>
using namespace std;
#define N 5
int arr[N];
int sum;
int main(void){
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sum += arr[i]*arr[i];
    }
    cout << sum%10 << "\n";
    return 0;
}