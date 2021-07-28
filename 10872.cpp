#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int n;
int factorial(int x) {
    if(x == 0) {
        return 1;
    }
    return x * factorial(x-1);
}
int main(void) {
    cin >> n;
    cout << factorial(n) << endl;
    return 0; 
}