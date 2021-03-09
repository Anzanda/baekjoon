#include <iostream>
using namespace std;

int n, m;
int reverseCount;
int a[50][50];
char field[50][50];
void check(int i, int j){
    if(a[i][j]){
        for(int x=i; x<=i+2; x++){
            for(int y=j; y<=j+2; y++){
                if(a[x][y]) a[x][y] = 0;
                else        a[x][y] = 1;
            }
        }
        reverseCount++;
    }
}
int main(void){
    cin >> n >> m;

    char input_char;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input_char;
            a[i][j] = input_char-'0';
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input_char;
            if(a[i][j]==input_char-'0'){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 1;
            }
        }
    }
    

    reverseCount = 0;
    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=m-3; j++){
            check(i, j);
        }
    }


    bool flag = true;
    for(int i=0; i<n && flag; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]){
               flag = false;
               break; 
            }
        }
    }
    if(flag)    cout << reverseCount;
    else        cout << -1;

}