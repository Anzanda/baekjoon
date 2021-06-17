#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

int n;
int ans;
int board[MAXN];
void nQueen(int x){
    if(x == n){
        ans++;
        return;
    }
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=0; j<x; j++){
            if(board[j] == i || abs(board[j]-i) == abs(j-x)){ //col변화량 == row변화량.
                flag=false;
                break;
            }
        }   
        if(flag){
            board[x] = i;
            nQueen(x+1);
        }
    }
}
int main(void){
    cin >> n;
    nQueen(0);
    cout << ans;
    return 0;
}