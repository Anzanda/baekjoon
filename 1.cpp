#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int main(void){
    cin >> n;
    ans = (int)(n * 1.08);
    if(ans > 206){
        cout << ":(" << "\n";
    }
    else if(ans == 206){
        cout << "so-so" << "\n";
    }
    else{
        cout << "Yay!" << "\n";
    }
    return 0;
}